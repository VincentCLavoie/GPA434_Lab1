/*  Color.cpp
 *  Cette classe représente les colors des formes polygonales en format R, G, B.
 *
 *  Note: Pour chacune des formes, on doit spécifier deux couleurs:
 *    - Couleur des segments;
 *    - Couleur de remplissage de la forme.
 *
 *  De plus, on permet la spécification de la transparence d'une couleur par
 *  le biais d'une valeur alpha (alpha channel). Ainsi, alpha = 1.0
 *  signifie opacité maximale.
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques C++ à étudier
 *  ------------------------------------------------------------------------------------------
 *  Cette classe implante concrètement les constructeurs de copie et par assignation. Voir
 *  ce fichier pour les détails.
 *  ------------------------------------------------------------------------------------------
 *
 *
 *  Code modifié par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de données: PascalCase
 *    Variables, fonctions: camelCase
 */
#include "Color.h"

// Constructeur par défaut
// R, G, B = 0.0f avec opacité maximale
Color::Color()
    : Color(0.0f, 0.0f, 0.0f, 1.0f)
{
}

// Constructeur avec paramètres
Color::Color(float red, float green, float blue, float alpha)
    : mRed{ red }, mGreen{ green }, mBlue{ blue }, mAlpha{ alpha } 
{
}

// Destructeur de la classe
Color::~Color()
{
    // do nothing
}

// Constructeur de copie
// Permet d'écrire dans le code: Color c1; Color c2(c1);
Color::Color(const Color& p) {
  mRed = p.mRed; mGreen = p.mGreen;
  mBlue = p.mBlue; mAlpha = p.mAlpha;
}

// Constructeur par assignation
// Permetttre d'écrire dans le code: Color c1; Color c2 = c1;
Color& Color::operator=(const Color& c) {
  mRed = c.mRed; mGreen = c.mGreen;
  mBlue = c.mBlue; mAlpha = c.mAlpha;

  return *this;
}


// Accesseur(s) et mutateur(s) (fonctions membres)
float Color::red() const
{
  return mRed;
}

float Color::green() const
{
  return mGreen;
}

float Color::blue() const
{
  return mBlue;
}

float Color::alpha() const
{
  return mAlpha;
}

void Color::setRed(float const& red)
{
  mRed = red;
}

void Color::setGreen(float const& green)
{
  mGreen = green;
}

void Color::setBlue(float const& blue)
{
  mBlue = blue;
}

void Color::setAlpha(float const& alpha)
{
  mAlpha = alpha;
}

void Color::set(float const& red, float const& green, float const& blue, float const& alpha)
{
  setRed(red);
  setGreen(green);
  setBlue(blue);
  setAlpha(alpha);
}

