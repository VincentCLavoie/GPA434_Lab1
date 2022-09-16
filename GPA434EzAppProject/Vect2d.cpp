/*  Vect2d.cpp
 *  Cette classe repr�sente un vecteur dans le plan 2D. Le vecteur est exprim� par rapport
 *  � l'origine des axes x et y. Le vecteur jouera le r�le d'un segment dans un forme polygonale.
 *
 *  Cette classe poss�de les coordonn�es X et Y. Elle est aussi capable de calculer:
 *    - Sa longueur (norm);
 *    - Sa longueur au carr� (norm_squared);
 *    - Son angle (theta) par rapport � l'axe des x;
 *    - Sa distance par rapport � un autre vecteur (distance).
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques � �tudier
 *  ------------------------------------------------------------------------------------------ 
 *  Cette classe est dot�e d'op�rateurs arithm�tiques (operator overload) afin de simplifier
 *  l'�criture du code:
 *    - Op�rateur + pour addition deux vecteurs;
 *    - Op�rateur += pour additionner deux vecteurs;
 *    - Op�rateurs * pour multiplier un vecteur par une valeur en simple pr�cision (float).
 *  ------------------------------------------------------------------------------------------
 * 
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de donn�es: PascalCase
 *    Variables, fonctions: camelCase
 */
#include "Vect2d.h"
#include <cmath>

// Constructeur par d�faut
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
// Permet d'�crire dans le code: Vect2d v1; Vect2d v2(v1);
Vect2d::Vect2d(const Vect2d& p)
{
  mX = p.mX;
  mY = p.mY;
}

// Constructeur par assignation
// Permetttre d'�crire dans le code: Color c1; Color c2 = c1;
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

// M�thodes (fonctions membres)
float Vect2d::distance_squared(Vect2d const& another) const
{
  // Ici, la distance entre deux vecteurs V1 et V2 est �quivalente
  // � la distance entre deux points puisque les vecteurs sont d�finies
  // par rapport � l'origine (0, 0).
  return std::powf(mX - another.mX, 2.0f) + std::powf(mY - another.mY, 2.0f);
}

float Vect2d::distance(Vect2d const& another) const
{
  // Ici, la distance entre deux vecteurs V1 et V2 est �quivalente
  // � la distance entre deux points puisque les vecteurs sont d�finies
  // par rapport � l'origine (0, 0).
  return std::sqrt(distance_squared(another));
}

void Vect2d::reset()
{
  mX = mY = 0.0f;
}

// La surcharge de l'op�rateur arith�mtique + (addition)
// L'op�rateur + prend deux op�randes: lhs + rhs
//
//  - lhs et rhs sont des objets de classe Vect2d
//  - lhs signifie l'objet � gauche de l'op�rateur (cet objet ci)
//  - rhs signifie l'objet � droite de l'op�rateur (l'obbjet pass� en param�tre)
//
Vect2d Vect2d::operator+(Vect2d rhs) const
{
  // Attention! Ici, c'est l'objet rhs qui est modifi�.
  rhs.mX += mX;
  rhs.mY += mY;
  return rhs;
}

// La surcharge de l'op�rateur arith�mtique += (addition et assignation)
// L'op�rateur += prend deux op�randes: lhs += rhs est �quivalent � lhs = lsh + rhs
//
//  - lhs et rhs sont des objets de classe Vect2d
//  - lhs signifie l'objet � gauche de l'op�rateur (cet objet ci)
//  - rhs signifie l'objet � droite de l'op�rateur (l'obbjet pass� en param�tre)
//
Vect2d& Vect2d::operator+=(Vect2d const& rhs)
{
  // Attention! Ici, c'est l'objet lhs qui est modifi�.
  mX += rhs.mX;
  mY += rhs.mY;
  return *this;
}

// La surcharge de l'op�rateur arith�mtique * (multiplication)
// L'op�rateur * prend deux op�randes: lhs * rhs
//
//  - rhs est un scalaire de simple pr�cision
//  - lhs signifie l'objet � gauche de l'op�rateur (cet objet ci)
//  - rhs signifie l'objet � droite de l'op�rateur (l'obbjet pass� en param�tre)
//
Vect2d Vect2d::operator*(float const& rhs) const
{
  // Attention! Ici, le r�sultat de la multiplication est plac�
  // dans un nouvel objet puis retourn� au programme � l'endroit o� cet op�rateur
  // est ex�cut�.
  return Vect2d(mX * rhs, mY * rhs);
}

// La surcharge de l'op�rateur arith�mtique * (multiplication) par une fonction amie
// L'op�rateur * prend deux op�randes: lhs * rhs
//
//  - lhs est un scalaire de simple pr�cision
//  - lhs signifie l'objet � gauche de l'op�rateur (cet objet ci)
//  - rhs signifie l'objet � droite de l'op�rateur (l'obbjet pass� en param�tre)
//
// Note: On utilise une fonction amie pour r�aliser cette surcharge � la place d'une
//       fonction membre car le lhs n'est pas un objet Vect2d mais bien une valeur
//       simple pr�cision. Ex.: 0.5f * v1
Vect2d operator*(float lhs, Vect2d const& rhs)
{
  return rhs * lhs;
}

