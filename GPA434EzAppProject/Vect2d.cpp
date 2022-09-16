/*  Vect2d.cpp
 *  Cette classe représente un vecteur dans le plan 2D. Le vecteur est exprimé par rapport
 *  à l'origine des axes x et y. Le vecteur jouera le rôle d'un segment dans un forme polygonale.
 *
 *  Cette classe possède les coordonnées X et Y. Elle est aussi capable de calculer:
 *    - Sa longueur (norm);
 *    - Sa longueur au carré (norm_squared);
 *    - Son angle (theta) par rapport à l'axe des x;
 *    - Sa distance par rapport à un autre vecteur (distance).
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques à étudier
 *  ------------------------------------------------------------------------------------------ 
 *  Cette classe est dotée d'opérateurs arithmétiques (operator overload) afin de simplifier
 *  l'écriture du code:
 *    - Opérateur + pour addition deux vecteurs;
 *    - Opérateur += pour additionner deux vecteurs;
 *    - Opérateurs * pour multiplier un vecteur par une valeur en simple précision (float).
 *  ------------------------------------------------------------------------------------------
 * 
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de données: PascalCase
 *    Variables, fonctions: camelCase
 */
#include "Vect2d.h"
#include <cmath>

// Constructeur par défaut
Vect2d::Vect2d(float x, float y)
  : mX{ x }, mY{ y }
{
}

// Desctructeur
Vect2d::~Vect2d()
{
  // do nothing
}

// Constructeur de copie
// Permet d'écrire dans le code: Vect2d v1; Vect2d v2(v1);
Vect2d::Vect2d(const Vect2d& p)
{
  mX = p.mX;
  mY = p.mY;
}

// Constructeur par assignation
// Permetttre d'écrire dans le code: Color c1; Color c2 = c1;
Vect2d& Vect2d::operator=(const Vect2d& c) {
  mX = c.mX;
  mY = c.mY;
  return *this;
}

// Accesseur(s) et mutateur(s) (fonctions membres)
float Vect2d::x() const
{
  return mX;
}

float Vect2d::y() const
{
  return mY;
}

float Vect2d::norm_squared() const
{
  return mX * mX + mY * mY;
}

float Vect2d::norm() const
{
  return std::sqrt(norm_squared());
}

float Vect2d::theta() const
{
  return std::atan2(mY, mX);
}

void Vect2d::setX(float const& x)
{
  mX = x;
}

void Vect2d::setY(float const& y)
{
  mY = y;
}

void Vect2d::set(float const& x, float const& y)
{
  setX(x);
  setY(y);
}

void Vect2d::setFromPolar(float const& norm, float const& thetaRadians)
{
  setX(norm * std::cos(thetaRadians));
  setY(norm * std::sin(thetaRadians));
}

// Méthodes (fonctions membres)
float Vect2d::distance_squared(Vect2d const& another) const
{
  // Ici, la distance entre deux vecteurs V1 et V2 est équivalente
  // à la distance entre deux points puisque les vecteurs sont définies
  // par rapport à l'origine (0, 0).
  return std::powf(mX - another.mX, 2.0f) + std::powf(mY - another.mY, 2.0f);
}

float Vect2d::distance(Vect2d const& another) const
{
  // Ici, la distance entre deux vecteurs V1 et V2 est équivalente
  // à la distance entre deux points puisque les vecteurs sont définies
  // par rapport à l'origine (0, 0).
  return std::sqrt(distance_squared(another));
}

void Vect2d::reset()
{
  mX = mY = 0.0f;
}

// La surcharge de l'opérateur arithémtique + (addition)
// L'opérateur + prend deux opérandes: lhs + rhs
//
//  - lhs et rhs sont des objets de classe Vect2d
//  - lhs signifie l'objet à gauche de l'opérateur (cet objet ci)
//  - rhs signifie l'objet à droite de l'opérateur (l'obbjet passé en paramètre)
//
Vect2d Vect2d::operator+(Vect2d rhs) const
{
  // Attention! Ici, c'est l'objet rhs qui est modifié.
  rhs.mX += mX;
  rhs.mY += mY;
  return rhs;
}

// La surcharge de l'opérateur arithémtique += (addition et assignation)
// L'opérateur += prend deux opérandes: lhs += rhs est équivalent à lhs = lsh + rhs
//
//  - lhs et rhs sont des objets de classe Vect2d
//  - lhs signifie l'objet à gauche de l'opérateur (cet objet ci)
//  - rhs signifie l'objet à droite de l'opérateur (l'obbjet passé en paramètre)
//
Vect2d& Vect2d::operator+=(Vect2d const& rhs)
{
  // Attention! Ici, c'est l'objet lhs qui est modifié.
  mX += rhs.mX;
  mY += rhs.mY;
  return *this;
}

// La surcharge de l'opérateur arithémtique * (multiplication)
// L'opérateur * prend deux opérandes: lhs * rhs
//
//  - rhs est un scalaire de simple précision
//  - lhs signifie l'objet à gauche de l'opérateur (cet objet ci)
//  - rhs signifie l'objet à droite de l'opérateur (l'obbjet passé en paramètre)
//
Vect2d Vect2d::operator*(float const& rhs) const
{
  // Attention! Ici, le résultat de la multiplication est placé
  // dans un nouvel objet puis retourné au programme à l'endroit où cet opérateur
  // est exécuté.
  return Vect2d(mX * rhs, mY * rhs);
}

// La surcharge de l'opérateur arithémtique * (multiplication) par une fonction amie
// L'opérateur * prend deux opérandes: lhs * rhs
//
//  - lhs est un scalaire de simple précision
//  - lhs signifie l'objet à gauche de l'opérateur (cet objet ci)
//  - rhs signifie l'objet à droite de l'opérateur (l'obbjet passé en paramètre)
//
// Note: On utilise une fonction amie pour réaliser cette surcharge à la place d'une
//       fonction membre car le lhs n'est pas un objet Vect2d mais bien une valeur
//       simple précision. Ex.: 0.5f * v1
Vect2d operator*(float lhs, Vect2d const& rhs)
{
  return rhs * lhs;
}

