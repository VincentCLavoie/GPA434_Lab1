/*  Polygon.h
 *  Cette classe repr�sente une suite de segments de droites cons�cutifs donnant une forme
 *  polygonale ferm�e. Ces segments sont encod�s par des sommets (en anglais "vertex" au
 *  singulier et au pluriel "vertices"). Par exemple, pour la forme polygonale suivante
 *
 *                    --------
 *                   /        \
 *            ______/          \______
 *           |          Cx,Cy         |
 *           |________________________|
 *
 *  poss�de 8 sommets. La position Cx, Cy repr�sente le centre de la forme. Ainsi, dans le
 *  contexte de ce laboratoire, les sommets seront d�finis par rapport au point Cx, Cy de
 *  la forme polygonale.
 *
 *  Cette classe utilise les classes suivantes:
 *    - Color : pour la couleur des segments et du remplissage de la forme polygonale;
 *    - Vect2d : pour g�rer un segment sous forme d'un sommet;
 *    - vector : pour g�rer les segments de la forme polygonale. Noter que vector
 *               fait partie de la biblioth�que standard STL du langage C++;
 *    - EzApp : pour le tra�age graphique de la forme polygonale;
 *    - string: pour g�rer les cha�nes de caract�res. Noter que string fait partie de
 *              la biblioth�que standard STL du langage C++.
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques � �tudier
 *  ------------------------------------------------------------------------------------------
 *     - D�finition d'une forme polygonale � partir des sommets;
 *     - �tapes n�cessaires pour tracer un polygone dans une fen�tre EzApp;
 *     - �tapes n�cessaires pour tracer une ligne de texte dans une fen�tre EzApp.
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
#ifndef POLYGON_H
#define POLYGON_H

#include "Color.h"
#include "Vect2d.h"
#include <vector>
#include <EzApp>
#include <iostream>
#include <string>

class Polygon
{
public:
    Polygon();                                // constructeur par d�faut
    ~Polygon();                               // destructeur
    Polygon(const Polygon& p) = default;       // constructeur de copie
    Polygon& operator=(const Polygon& c) = default;     // constructeur par assignation


    // Accesseur(s) et mutateur(s) (fonctions membres)
    void setFill(Color const& fillColor);
    void setOutline(Color const& outlineColor, float const& outlineWidth = 1.0f);
    void setColors(Color const& fillColor, Color const& outlineColor, float const& outlineWidth = 1.0f);

    // Accesseur(s) et mutateur(s) (fonctions membres)
    Color fillColor() const;
    Color outlineColor() const;
    float outlineWidth() const;

    // --------------------------------------------------------------------------
    // M�thodes pour construire les formes polygonales
    // Pour cette �tape, on sait construire l'ast�ro�de
    // --------------------------------------------------------------------------

    void buildSpaceship(Color const& inside, Color const& outLine,
        float const& x = 0.0f, float const& y = 0.0f,
        float const& outlineWidth = 1.0f);

    void buildasteroid(float const& summitCount, Color const& inside, Color const& outline,
        float const& outlineWidth);

    void buildMissile(Color const& inside, Color const& outLine,
        float const& x = 0.0f, float const& y = 0.0f,
        float const& outlineWidth = 1.0f);

    // M�thodes pour faire le tra�age sur le canvas (�cran) EzApp
    void draw(ezapp::Screen& screen, float const& x = 0.0f, float const& y = 0.0f, float const& rotation = 0.0f,
        float const& scale = 1.0f) const;
    void drawText(ezapp::Screen& screen, std::string const& text, float const& x, float const& y,
        float const& rotation = 0.0f, float const& scale = 1.0f, float const& lineWidth = 1.0f,
        size_t characterSize = 30, float const& letterSpacingRatio = 1.0f,
        float const& lineSpacingRatio = 1.0f, bool const& bold = false, bool const& italic = false,
        bool const& underline = false, bool const& strikeThrough = false) const;
    std::string strTo1Decimals(std::string const& inStr); // change string to 1 decimal

private:
    std::vector<Vect2d> mVertex;    // vecteur de sommets
    Color mFillColor;               // couleur de remplissage
    Color mOutlineColor;            // couleur des segments
    float mOutlineWidth;            // �paisseur des segments

};
#endif //POLYGON_H

