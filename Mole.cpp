#include "Mole.h"

Mole::Mole()
{
    visible = false;
    pos = VGet(0, 0, 0);
}

void Mole::SetPos(VECTOR p)
{
    pos = p;
}

void Mole::Show()
{
    visible = true;
}

void Mole::Hide()
{
    visible = false;
}

bool Mole::IsVisible() const
{
    return visible;
}

VECTOR Mole::GetPos() const
{
    return pos;
}

void Mole::Draw()
{
    if (!visible)
    {
        return;
    }

    DrawSphere3D(
        VGet(pos.x, 5.0f, pos.z),
        2.5f,
        16,
        GetColor(139, 69, 19),
        GetColor(139, 69, 19),
        TRUE);
}