#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include <string>
#include <iostream>

#include "ast_node.hpp"

class Declaration : public Node{
    private:
        NodePtr type;
        NodePtr id;
        NodePtr value;
    public:
        Declaration (NodePtr _type, NodePtr _id, NodePtr _value)
            :   type(_type),
                id(_id),
                value(_value)
            {}

        virtual const char *getOpcode(){return "=";}

        std::string gettype() const override
        { return (type!=NULL) ? type->gettype() : "NULL"; }

        std::string getId() const override
        { return id->getId(); }

        NodePtr getvalue() const
        { return value; }

        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4);
            if (type!=NULL){
                type->print(dst,span);
            }
            id->print(dst, span);
            if (value!=NULL){
                dst<<"=";
                value->print(dst, span);
            }
            dst<<std::endl;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::string> &bindings)const override{
                if (type!=NULL){
                    std::string reg = helper.allocateReg();
                    bindings[id->getId()] = reg;
                    if (value!=NULL){
                        value->riscv_asm(dst, helper, reg, bindings);
                    }
                }
                else{
                    if (bindings.count(id->getId())){
                        std::string reg = bindings[id->getId()];
                        value->riscv_asm(dst, helper, reg, bindings);
                    }
                    else{
                        std::cerr<< "Trying to access variable that does not exist"<<std::endl;
                        exit(1);
                    }
                }
            }


};

#endif