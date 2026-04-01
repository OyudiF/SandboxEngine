#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "MainMenuState.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Sandbox Engine v0.1");
    window.setFramerateLimit(60);

    // Criacao da pilha de estados
    StateMachine machine;

    // Menu inicial como estado ativo
    machine.addState(std::make_unique<MainMenuState>(machine, window));

    sf::Clock clock;

    // Game loop universal
    while (window.isOpen()) {
        machine.processStateChanges();

        float dt = clock.restart().asSeconds();

        // pega o topo da pilha
        auto& currentState = machine.getActiveState();

        // Roda o ciclo de vida da tela
        currentState->handleInput();
        currentState->update(dt);

        window.clear(sf::Color(30, 30, 30));
        currentState->draw(window); // tela ativa tem que desenhar os autores
        window.display();
    }

    return 0;
}