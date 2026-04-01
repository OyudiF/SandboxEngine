#include "MainMenuState.h"
#include <iostream>

// LIsta de inicializacao: Guardamos as referencias que vieram do construtor
MainMenuState::MainMenuState(StateMachine &machine, sf::RenderWindow &window)
    : _machine(machine), _window(window) {
}

void MainMenuState::init() {
    // Retangulo verde no meio da tela para ser o botao
    _playButton.setSize({200.f, 50.f});
    _playButton.setFillColor(sf::Color::Green);
    _playButton.setPosition({300.f, 275.f});

    std::cout << "Menu Inicial Carregado com Sucesso!" << std::endl;
}

void MainMenuState::handleInput() {
    // O menu le os eventos da tela
    while (const auto event = _window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            _window.close();
        }

        // Se apertar a tecla ENTER
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
            std::cout << "Botao Jogar pressionado! (No futuro, carregaremos o GameState aqui)" << std::endl;
        }
    }
}

void MainMenuState::update(float dt) {

}

void MainMenuState::draw(sf::RenderWindow &window) {
    window.draw(_playButton);
}
