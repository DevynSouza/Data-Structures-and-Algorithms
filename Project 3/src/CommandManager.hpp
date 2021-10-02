#pragma once
#include "Stack.hpp"
#include "BattleMove.hpp"



class CommandManager {
    private:
        Stack<UndoableCommand*> stack; 

    public:
        CommandManager() :stack{ Stack<UndoableCommand*>(100) } {}
        void Execute(UndoableCommand* command){
            command -> Execute();
            stack.Push(command);
        };
        void Undo() {
            if(stack.IsEmpty()) {
                cout << "Nothing to undo" << endl;
                return;
            }
            UndoableCommand* command = stack.Top();
            command->Undo();
            delete stack.Top();
            stack.Pop();
        };

    };
