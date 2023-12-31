#ifndef ast_relational_hpp
#define ast_relational_hpp

#include "ast_operator.hpp"



class GthanOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return ">"; }
    public:
        GthanOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string mem = helper.allocateMemory();
                dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                reg_left = helper.allocateReg(datatype);
                dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                helper.last_mem_allocated += helper.min_mem;

                //>
                dst<<"sgt "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);

        }
};

class LthanOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "<"; }
    public:
        LthanOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{


                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string mem = helper.allocateMemory();
                dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                reg_left = helper.allocateReg(datatype);
                dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                helper.last_mem_allocated += helper.min_mem;

                //<
                dst<<"slt "<<destReg<<", "<<reg_left<<", "<<reg_right<<std::endl;

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);

        }
};

class GthanEqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return ">="; }
    public:
        GthanEqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string mem = helper.allocateMemory();
                dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                reg_left = helper.allocateReg(datatype);
                dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                helper.last_mem_allocated += helper.min_mem;

                //>=
                dst<<"slt "<<reg_left<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"xori "<<destReg<<", "<<reg_left<<", 1"<<std::endl;     //bitwise xor i.e. invert

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);

        }
};

class LthanEqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "<="; }
    public:
        LthanEqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string mem = helper.allocateMemory();
                dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                reg_left = helper.allocateReg(datatype);
                dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                helper.last_mem_allocated += helper.min_mem;

                //<=
                dst<<"sgt "<<reg_left<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"xori "<<destReg<<", "<<reg_left<<", 1"<<std::endl;    //bitwise xor i.e. invert

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);

        }
};

class EqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "=="; }
    public:
        EqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }


        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string mem = helper.allocateMemory();
                dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                reg_left = helper.allocateReg(datatype);
                dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                helper.last_mem_allocated += helper.min_mem;

                //>=
                dst<<"sub "<<reg_left<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"seqz "<<destReg<<", "<<reg_left<<std::endl;     //set equal 0

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);

        }
};

class NEqOperator: public Operator{
    protected:
        virtual const char *getOpcode() const override
        { return "!="; }
    public:
        NEqOperator(NodePtr _left, NodePtr _right)
            : Operator(_left, _right)
        {}

        virtual double evaluate(
            const std::map<std::string,double> &bindings
        ) const override
        {
            // TODO-C :  evaluate functions not in use at the moment
            double vl=getLeft()->evaluate(bindings);
            double vr=getRight()->evaluate(bindings);
            return vl+vr;
        }

        virtual void riscv_asm(std::ostream &dst,
            Helper &helper,
            std::string destReg,
            std::map<std::string, std::vector<std::string>> &bindings,
            std::string datatype = "None")const override{

                std::string reg_left = helper.allocateReg(datatype);
                left->riscv_asm(dst, helper, reg_left, bindings);
                std::string mem = helper.allocateMemory();
                dst<<"sw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                std::string reg_right = helper.allocateReg(datatype);
                right->riscv_asm(dst, helper, reg_right, bindings);
                reg_left = helper.allocateReg(datatype);
                dst<<"lw "<<reg_left<<", "<<mem<<"(sp)"<<std::endl;
                helper.last_mem_allocated += helper.min_mem;

                //>=
                dst<<"sub "<<reg_left<<", "<<reg_left<<", "<<reg_right<<std::endl;
                dst<<"snez "<<destReg<<", "<<reg_left<<std::endl;     //set not equal 0

                dst<<"addi "<<reg_left<<", zero, 0"<<std::endl;
                dst<<"addi "<<reg_right<<", zero, 0"<<std::endl;
                helper.deallocateReg(reg_left);
                helper.deallocateReg(reg_right);

        }
};


#endif
