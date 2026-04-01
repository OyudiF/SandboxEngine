#ifndef SANDBOXENGINE_MAINMENUSTATE_H
#define SANDBOXENGINE_MAINMENUSTATE_H

#pragma once
#include "State.h"
#include "StateMachine.h"
#include <SFML/Graphics.hpp>

class MainMenuState : public State {
public:
    // Construtor recebe referencias para a maquina e janela
    MainMenuState(StateMachine& machine, sf::RenderWindow& window);
    ~MainMenuState() = default;

    // Contrato da classe abstrata State
    void init() override;
    void handleInput() override;
    void update(float dt) override;
    void draw(sf::RenderWindow &window) override;

private:
    StateMachine& _machine; // Referencia a pilha
    sf::RenderWindow& _window; // Referencia a janela

    sf::RectangleShape _playButton; // Botao provisorio
};

#endif //SANDBOXENGINE_MAINMENUSTATE_H
