#include "StateMachine.h"

void StateMachine::addState(StateRef newState, bool isReplacing) {
    _isAdding = true;
    _isReplacing = isReplacing;

    // move transfere a "posse" da memoria para a nossa maquina de estados
    _newState = std::move(newState);
}

void StateMachine::removeState() {
    _isRemoving = true;
}

void StateMachine::processStateChanges() {
    // Se pedirem para remover a tela atual (e a pilha nao estiver vazia)
    if (_isRemoving && !_states.empty()) {
        _states.pop(); // remove o topo

        // Se sobra alguma tela embaixo, avisamos ela para "acordar" (resume)
        if (!_states.empty()) {
            _states.top()->resume();
        }
        _isRemoving = false;
    }

    // Se pediram para adicionar uma tela nova
    if (_isAdding) {
        if (!_states.empty()) {
            if (_isReplacing) {
                _states.pop(); // Joga a tela antiga no lixo
            } else {
                _states.top()->pause(); // Congela a tela antiga
            }
        }

        // Coloca a tela nova no topo da pilha e inicializa ela
        _states.push(std::move(_newState));
        _states.top()->init();
        _isAdding = false;
    }
}

StateRef &StateMachine::getActiveState() {
    return _states.top();
}
