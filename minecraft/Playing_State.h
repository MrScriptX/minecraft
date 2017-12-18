#ifndef PLAYING_H_INCLUDED
#define PLAYING_H_INCLUDED

#include "Game_States.h"

#include "Model.h"
#include "Simple_Shader.h"
#include "Basic_Texture.h"

#include "Quad.h"

class Application;

namespace State
{
    class Playing : public Game_State
    {
        public:
            Playing(Application& application);

            void input  (Entity& camera) override;
            void update (Entity& camera) override;
            void draw   (Renderer::Master& renderer) override;

        private:
            Shader::Simple_Shader m_shader;
            Texture::Basic_Texture m_texture;

            //Quad m_quad;

            std::vector<Quad*> m_quads;
    };
}


#endif // PLAYING_H_INCLUDED
