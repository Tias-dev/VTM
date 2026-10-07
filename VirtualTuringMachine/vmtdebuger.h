#ifndef VMTDEBUGER_H
#define VMTDEBUGER_H

#include <memory>
#include <stack>

#include "VMTAlphabit.h"
#include "VMTLine.h"
#include "vmtmachines/VMTComplexMachine.h"

class VMTDebuger {
   protected:
    std::shared_ptr<VMTLine> _line;
    std::shared_ptr<VMTComplexMachine> _complex_machine;

    class State {
       public:
        std::shared_ptr<VMTComplexMachine> complex_machine;
        std::shared_ptr<IVMTMachine> machine;
    };

    std::stack<State> _stack;
    State _state;
    VMTDebuger::State FindNextMachine();

   public:
    VMTDebuger(std::shared_ptr<VMTAlphabit> alphabit,
               std::shared_ptr<VMTComplexMachine> complex_machine);

    std::shared_ptr<VMTLine> GetLine();
    std::shared_ptr<VMTComplexMachine> GetComplexMachine();

    void ToStart(IVMTEnvironment* environment);
    bool IsFinish();
    void Step(IVMTEnvironment* environment);
};

#endif  // VMTDEBUGER_H
