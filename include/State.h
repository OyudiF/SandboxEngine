#ifndef SANDBOXENGINE_STATE_H
#define SANDBOXENGINE_STATE_H

#pragma once
#include <SFML/Graphics.hpp>

class State {
public:
    // Garante memoria seja limpa
    virtual ~State() = default;

    // Virtuais puros (=0), as classes sao obrigadas a usar
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    // Opcionais
    virtual void pause() {}
    virtual void resume() {}
};

#endif //SANDBOXENGINE_STATE_H
