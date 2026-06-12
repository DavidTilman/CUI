#include "TextBlock.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cstdio>
#include <string>

void TextBlock::Draw(SDL_Renderer* renderer, SDL_FRect* pane) {
    std::string boundText;
    const char* displayText = text;
    if (textBinding) {
        boundText = textBinding();
        displayText = boundText.c_str();
    }

    if (!displayText) return;
    if (!this->fontFamily) return;

    SDL_FRect dst = Measure(pane);

    SDL_SetRenderDrawColor(renderer, background.R, background.G, background.B, background.A);
    SDL_RenderFillRect(renderer, &dst);

    TTF_Font* font = TTF_OpenFont(fontFamily, fontSize);

    TTF_TextEngine* engine = TTF_CreateRendererTextEngine(renderer);

    TTF_Text* ttfText = TTF_CreateText(engine, font, displayText, 0);

    TTF_SetTextColor(ttfText, foreground.R, foreground.G, foreground.B, foreground.A);

    TTF_DrawRendererText(ttfText, dst.x + (float)padding.l, dst.y + (float)padding.t);

    TTF_DestroyText(ttfText);
    TTF_DestroyRendererTextEngine(engine);
    TTF_CloseFont(font);
}

void TextBlock::debug_print_content(const std::string& prefix, bool is_last) {
    const char* conn = is_last ? "└── " : "├── ";
    std::string ppfx = prefix + (is_last ? "    " : "│   ") + "│  ";
    printf("%s%sTextBlock @ %p\n", prefix.c_str(), conn, this);
    printf("%s%-12s = \"%s\"\n",          ppfx.c_str(), "text",       text       ? text       : "(null)");
    printf("%s%-12s = \"%s\"\n",          ppfx.c_str(), "fontFamily", fontFamily ? fontFamily : "(null)");
    printf("%s%-12s = %.1f\n",            ppfx.c_str(), "fontSize",   fontSize);
    printf("%s%-12s = #%02X%02X%02X%02X\n", ppfx.c_str(), "foreground", foreground.R, foreground.G, foreground.B, foreground.A);
    printf("%s%-12s = #%02X%02X%02X%02X\n", ppfx.c_str(), "background", background.R, background.G, background.B, background.A);
    printf("%s%-12s = l=%u r=%u t=%u b=%u\n", ppfx.c_str(), "padding",   padding.l, padding.r, padding.t, padding.b);
    printf("%s%-12s = l=%u r=%u t=%u b=%u\n", ppfx.c_str(), "margin",    margin.l, margin.r, margin.t, margin.b);
    printf("%s%-12s = %.0f x %.0f\n",     ppfx.c_str(), "size",       width, height);
}
