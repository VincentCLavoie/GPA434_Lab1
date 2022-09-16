/*  Vect2d.h
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
#pragma once
#ifndef VECT_2D_H
#define VECT_2D_H


class Vect2d
{
public:
  Vect2d(float x = 0.0f, float y = 0.0f);   // constructeur par d�faut
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

  // M�thodes (fonctions membres)
  float distance_squared(Vect2d const& another) const;
  float distance(Vect2d const& another) const;

  // Op�rateurs arithm�tiques surcharg�s par des fonctions membres
  //  - lhs signifie l'objet � gauche de l'op�rateur
  //  - rhs signifie l'objet � droite de l'op�rateur
  Vect2d operator+(Vect2d rhs) const;         // par exemple: v1 + v2
  Vect2d& operator+=(Vect2d const& rhs);      // par exemple: v1 += v2;
  Vect2d operator*(float const& rhs) const;   // par exemple: v1 * 5.0f
  // Fonction amie. Voir l'explication plus bas dans le fichier.
  friend Vect2d operator*(float lhs, Vect2d const& rhs); // par exemple: 5.0f * v1

private:
  float mX;
  float mY;

};

// Fonction amie de la classe Vect2d pour r�aliser l'op�ration arithm�tique
// du genre 5.0f * v1 par exemple.
// Raison: La surcharge des op�rateurs par des fonctions membres suppose que l'objet
//         lhs soit toujours un objet de la classe. Ici, 5.0f * v1, l'objet lhs
//         est une valeur simple pr�cision d'o� la n�cessit� d'utiliser une fonction
//         amie.
Vect2d operator*(float lhs, Vect2d const& rhs);


#endif //VECT_2D_H