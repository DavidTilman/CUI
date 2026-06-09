#include "TextBlock.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3_ttf/SDL_ttf.h>

void TextBlock::Draw(SDL_Renderer* renderer, SDL_FRect* pane) {
    if (!this->text) return;
    if (!this->fontFamily) return;

    SDL_SetRenderDrawColor(renderer, background.R, background.G, background.B, background.A);
    SDL_RenderFillRect(renderer, pane);

    TTF_Font* font = TTF_OpenFont(fontFamily, fontSize);  // ptsize is float in SDL3

    TTF_TextEngine* engine = TTF_CreateRendererTextEngine(renderer);

    TTF_Text* ttfText = TTF_CreateText(engine, font, text, 0);  // 0 = auto length

    TTF_SetTextColor(ttfText, foreground.R, foreground.G, foreground.B, foreground.A);
    TTF_DrawRendererText(ttfText, pane->x, pane->y);

    TTF_DestroyText(ttfText);
    TTF_DestroyRendererTextEngine(engine);
    TTF_CloseFont(font);
}
