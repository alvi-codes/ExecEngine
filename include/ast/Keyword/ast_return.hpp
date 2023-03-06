#ifndef ast_return_hpp
#define ast_return_hpp

#include <string>
#include <iostream>

#include "../ast_node.hpp"


class Return : public Node {

    private:
        NodePtr next;

    public:
        Return(NodePtr _next)
            : next(_next)
        {}


        virtual void print(std::ostream &dst, int span) const override{
            dst<<std::setw(span*4)<<"return ";
            if (next!=NULL){
                next->print(dst, span);
            }
            dst<<std::endl;
        }

        virtual double evaluate(const std::map<std::string,double> &bindings) const override{
            // If the binding does not exist, this will throw an error
            return next->evaluate(bindings);
        }


        virtual void riscv_gen(std::ostream &dst, Helper &helper, std::string destReg)const override{
            if (next!=NULL){
                if (next->getClass() == "Number"){
                    dst<<"addi t0, zero, 0"<<std::endl;
                    dst<<"addi t0, zero, "<<std::to_string(static_cast<int>(next->getValue()))<<std::endl;
                }
                dst<<"mv a0, t0"<<std::endl;
            }

        }
};

#endif
