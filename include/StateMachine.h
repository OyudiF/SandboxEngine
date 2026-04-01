#ifndef SANDBOXENGINE_STATEMACHINE_H
#define SANDBOXENGINE_STATEMACHINE_H

#pragma once
#include <memory>
#include <stack>
#include "State.h"

// Apelido para um ponteiro inteligente que guarda o estado
typedef std::unique_ptr<State> StateRef;

class StateMachine {
public:
    StateMachine() = default;
    ~StateMachine() = default;

    // Adiciona uma tela nova. isReplacing = true remove a tela anterior (ex: Menu -> Jogo)
    // isReplacing = false coloca a tela nova por cima (ex: Jogo -> Pause)
    void addState(StateRef newState, bool isReplacing = true);

    // Remove a tela do topo (ex: Sair do Pause e voltar pro jogo)
    void removeState();

    // o metodo que a Engine vai chamar para executar a troca com seguranca
    void processStateChanges();

    // Retorna a tela que esta rodando no momento
    StateRef& getActiveState();

private:
    std::stack<StateRef> _states;
    StateRef _newState;

    bool _isRemoving = false;
    bool _isAdding = false;
    bool _isReplacing = false;
};


#endif //SANDBOXENGINE_STATEMACHINE_H
