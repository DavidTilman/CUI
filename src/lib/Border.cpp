#include "Border.h"
#include <SDL3/SDL_render.h>

void Border::Draw(SDL_Renderer* renderer, SDL_FRect* pane) {
    SDL_FRect dst = Measure(pane);
    float sw = (float)strokeWeight;

    // Background
    SDL_SetRenderDrawColor(renderer, background.R, background.G, background.B, background.A);
    SDL_RenderFillRect(renderer, &dst);
    // Stroke
    SDL_SetRenderDrawColor(renderer, stroke.R, stroke.G, stroke.B, stroke.A);

    SDL_FRect edges[4] = {
        { dst.x,              dst.y,              dst.w,         sw            },
        { dst.x,              dst.y + dst.h - sw, dst.w,         sw            },
        { dst.x,              dst.y + sw,         sw,            dst.h - sw*2  },
        { dst.x + dst.w - sw, dst.y + sw,         sw,            dst.h - sw*2  },
    };
    SDL_RenderFillRects(renderer, edges, 4);

    if (content) {
        SDL_FRect contentPane = {
            dst.x + sw + padding.l,
            dst.y + sw + padding.t,
            dst.w - sw*2 - padding.l - padding.r,
            dst.h - sw*2 - padding.t - padding.b
        };
        content->Draw(renderer, &contentPane);
    }
}
