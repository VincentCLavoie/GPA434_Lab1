/*  Polygon.h
 *  Cette classe représente une suite de segments de droites consécutifs donnant une forme
 *  polygonale fermée. Ces segments sont encodés par des sommets (en anglais "vertex" au
 *  singulier et au pluriel "vertices"). Par exemple, pour la forme polygonale suivante
 *
 *                    --------
 *                   /        \
 *            ______/          \______
 *           |          Cx,Cy         |
 *           |________________________|
 *
 *  possède 8 sommets. La position Cx, Cy représente le centre de la forme. Ainsi, dans le
 *  contexte de ce laboratoire, les sommets seront définis par rapport au point Cx, Cy de
 *  la forme polygonale.
 *
 *  Cette classe utilise les classes suivantes:
 *    - Color : pour la couleur des segments et du remplissage de la forme polygonale;
 *    - Vect2d : pour gérer un segment sous forme d'un sommet;
 *    - vector : pour gérer les segments de la forme polygonale. Noter que vector
 *               fait partie de la bibliothèque standard STL du langage C++;
 *    - EzApp : pour le traçage graphique de la forme polygonale;
 *    - string: pour gérer les chaînes de caractères. Noter que string fait partie de
 *              la bibliothèque standard STL du langage C++.
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques à étudier
 *  ------------------------------------------------------------------------------------------
 *     - Définition d'une forme polygonale à partir des sommets;
 *     - Étapes nécessaires pour tracer un polygone dans une fenêtre EzApp;
 *     - Étapes nécessaires pour tracer une ligne de texte dans une fenêtre EzApp.
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
    Polygon();                                // constructeur par défaut
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
    // Méthodes pour construire les formes polygonales
    // Pour cette étape, on sait construire l'astéroïde
    // --------------------------------------------------------------------------

    void buildSpaceship(Color const& inside, Color const& outLine,
        float const& x = 0.0f, float const& y = 0.0f,
        float const& outlineWidth = 1.0f);

    void buildasteroid(float const& summitCount, Color const& inside, Color const& outline,
        float const& outlineWidth);

    void buildMissile(Color const& inside, Color const& outLine,
        float const& x = 0.0f, float const& y = 0.0f,
        float const& outlineWidth = 1.0f);

    // Méthodes pour faire le traçage sur le canvas (écran) EzApp
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
    float mOutlineWidth;            // épaisseur des segments

};
#endif //POLYGON_H

