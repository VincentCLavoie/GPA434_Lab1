/*  Color.h
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
 *  le fichier Color.cpp pour les détails.
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
#ifndef COLOR_H
#define COLOR_H


class Color
{
public:
  Color();                   // constructeur par défaut;
  Color(float red, float green, float blue, float alpha = 1.0f);
  ~Color();                  // destructeur
  Color(const Color& p);     // constructeur de copie
  Color& operator=(const Color & c);   // constructeur par assignation

  // Accesseur(s) et mutateur(s) (fonctions membres)
  float red() const;
  float green() const;
  float blue() const;
  float alpha() const;

  void setRed(float const& red);
  void setGreen(float const& green);
  void setBlue(float const& blue);
  void setAlpha(float const& alpha);
  void set(float const& red, float const& green, float const& blue, float const& alpha = 1.0f);

private:
    float mRed;
    float mGreen;
    float mBlue;
    float mAlpha;            // opacité
};

#endif //COLOR_H
