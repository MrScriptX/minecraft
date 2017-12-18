#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED

#include <vector>
#include <SFML/System/Clock.hpp>

#include "Simple_Shader.h"

class Quad;
struct Entity;

namespace Renderer
{
    class Simple
    {
        public:
            void draw (const Quad& quad);

            void update(const Entity& camera);

        private:
            void prepare(const Quad& quad);

        private:
            std::vector<const Quad*> m_quads;

            Shader::Simple_Shader m_shader;
            sf::Clock m_clock;
    };
}

#endif // SIMPLE_H_INCLUDED