/*  Vect2d.h
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
#pragma once
#ifndef VECT_2D_H
#define VECT_2D_H


class Vect2d
{
public:
  Vect2d(float x = 0.0f, float y = 0.0f);   // constructeur par défaut
  ~Vect2d();                                // destructeur
  Vect2d(const Vect2d& p);                  // constructeur de copie
  Vect2d& operator=(const Vect2d& c);       // constructeur par assignation

  // Accesseur(s) et mutateur(s) (fonctions membres)
  float x() const;
  float y() const;
  float norm_squared() const;
  float norm() const;
  float theta() const; // radians

  void setX(float const& x);
  void setY(float const& y);
  void set(float const& x, float const& y);
  void setFromPolar(float const& norm, float const& thetaRadians);
  void reset();

  // Méthodes (fonctions membres)
  float distance_squared(Vect2d const& another) const;
  float distance(Vect2d const& another) const;

  // Opérateurs arithmétiques surchargés par des fonctions membres
  //  - lhs signifie l'objet à gauche de l'opérateur
  //  - rhs signifie l'objet à droite de l'opérateur
  Vect2d operator+(Vect2d rhs) const;         // par exemple: v1 + v2
  Vect2d& operator+=(Vect2d const& rhs);      // par exemple: v1 += v2;
  Vect2d operator*(float const& rhs) const;   // par exemple: v1 * 5.0f
  // Fonction amie. Voir l'explication plus bas dans le fichier.
  friend Vect2d operator*(float lhs, Vect2d const& rhs); // par exemple: 5.0f * v1

private:
  float mX;
  float mY;

};

// Fonction amie de la classe Vect2d pour réaliser l'opération arithmétique
// du genre 5.0f * v1 par exemple.
// Raison: La surcharge des opérateurs par des fonctions membres suppose que l'objet
//         lhs soit toujours un objet de la classe. Ici, 5.0f * v1, l'objet lhs
//         est une valeur simple précision d'où la nécessité d'utiliser une fonction
//         amie.
Vect2d operator*(float lhs, Vect2d const& rhs);


#endif //VECT_2D_H