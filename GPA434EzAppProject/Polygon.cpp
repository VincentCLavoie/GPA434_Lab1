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
#include "Polygon.h"
#include <algorithm>

// Constructeur par défaut
Polygon::Polygon()
    : mVertex(3),                           // minimum trois sommets pour un polygone fermé
    mFillColor(1.0f, 1.0f, 1.0f, 1.0f),     // valeur RGB et transparence
    mOutlineColor(1.0f, 1.0f, 1.0f, 1.0f),
    mOutlineWidth{ 1.0f }                   // épaisseur des segments
{
}

// Destructeur
Polygon::~Polygon()
{
  // do nothing
}

// --------------------------------------------------------------------------------------
// Accesseur(s) et mutateur(s) (fonctions membres)
// --------------------------------------------------------------------------------------
void Polygon::setFill(Color const& fillColor)
{
  mFillColor = fillColor;
}

void Polygon::setOutline(Color const& outlineColor, float const& outlineWidth)
{
  mOutlineColor = outlineColor;
  mOutlineWidth = outlineWidth;
}

void Polygon::setColors(Color const& fillColor, Color const& outlineColor, float const& outlineWidth)
{
  setFill(fillColor);
  setOutline(outlineColor, outlineWidth);
}

Color Polygon::fillColor() const
{
  return mFillColor;
}

Color Polygon::outlineColor() const
{
  return mOutlineColor;
}

float Polygon::outlineWidth() const
{
  return mOutlineWidth;
}

// --------------------------------------------------------------------------------------
// Construction des formes polygonales
// Ainsi, un objet de type Polygon sait comment définir ses sommets pour donner les
// formes ci-dessous.
// --------------------------------------------------------------------------------------

void Polygon::buildSpaceship(Color const& inside, Color const& outLine, float const& x,
    float const& y, float const& outlineWidth)
{
    // Régler la couleur de remplissage, couleur des segments et
    // la largeur des segments.
    setColors(inside, outLine, outlineWidth);
    // Réserver le nombre de sommets
    mVertex.resize(6);
    // Indiquer les coordonnées des sommets dans l'ordre.
    mVertex[0].set(x, y - 35.0f);
    mVertex[1].set(x - 37.7f, y + 9.9f);
    mVertex[2].set(x - 31.6f, y + 15.0f);
    mVertex[3].set(x + 31.6f, y + 15.0f);
    mVertex[4].set(x + 37.7f, y + 9.9f);
    mVertex[5].set(x, y - 35.0f);
    
}


// Pour cette étape, on construire un astéroïde
void Polygon::buildasteroid(float const& summitCount, Color const& inside, Color const& outline, float const& outlineWidth)
{
    setColors(inside, outline, outlineWidth);
    mVertex.resize(std::max((size_t)5, (size_t)summitCount));
    // On utilise les coordonnées polaires (norme, theta) d'un Vect2d pour construire l'astéroïde
    // La forme irrégulière de l'astéroïde est obtenue grâce à l'utilisation de fonction aléatoire
    // rand() dans la génération des Vect2d.
    //
    // Contrainte: Chaque Vect2d aura une norme variant entre 10 à 30 unités et un angle theta
    //
    for (size_t i{}; i < mVertex.size(); ++i) {
        mVertex[i].setFromPolar((float)rand() / (float)RAND_MAX * (30 - 10) + 10, i * 2.0f * 3.141592654f /
            mVertex.size());
    }
}


// Pour cette étape, on construire un missile.
void Polygon::buildMissile(Color const& inside, Color const& outLine, float const& x,
    float const& y, float const& outlineWidth)
{
    setColors(inside, outLine, outlineWidth);
    // Réserver le nombre de sommets
    mVertex.resize(13);
    // Indiquer les coordonnées des sommets dans l'ordre.
    mVertex[0].set(x + 6.25f, y - 14.0f);
    mVertex[1].set(x, y - 20.0f);
    mVertex[2].set(x - 6.25f, y - 14.0f);
    mVertex[3].set(x - 6.25f, y - 8.0f);
    mVertex[4].set(x - 15.0F, y + 5.0f);
    mVertex[5].set(x - 6.25f, y + 5.0f);
    mVertex[6].set(x - 6.25f, y + 14.0f);
    mVertex[7].set(x - 15.0f, y + 25.0f);
    mVertex[8].set(x + 15.0f, y + 25.0f);
    mVertex[9].set(x + 6.25f, y + 14.0f);
    mVertex[10].set(x + 6.25f, y + 5.0f);
    mVertex[11].set(x + 15.0f, y + 5.0f);
    mVertex[12].set(x + 6.25f, y - 8.0f);
}

// --------------------------------------------------------------------------------------
// Traçage à l'écran
// Ainsi, un objet Polygon sait comment tracer ses segments, sous forme graphique, sur
// l'écran de EzApp.
// --------------------------------------------------------------------------------------
void Polygon::draw(ezapp::Screen& screen, float const& x, float const& y,
                   float const& rotation, float const& scale) const
{
  // Régler la brosse pour le remplissage
  screen.setBrush(mFillColor.red(),
                  mFillColor.green(),
                  mFillColor.blue(),
                  mFillColor.alpha());
  // Régler le crayon pour dessiner les segments
  screen.setPen(mOutlineColor.red(),
                mOutlineColor.green(),
                mOutlineColor.blue(),
                mOutlineColor.alpha(),
                mOutlineWidth);
  // Régler les sommets du polygone dans l'écran
  screen.setPolygonVertices(mVertex);
  // Tracer le polygone à l'écran
  screen.drawPolygon(x, y, rotation, scale);

}

void Polygon::drawText(ezapp::Screen& screen, std::string const& text, float const& x,
                       float const& y, float const& rotation, float const& scale,
                       float const& lineWidth, size_t characterSize, float const& letterSpacingRatio,
                       float const& lineSpacingRatio, bool const& bold, bool const& italic,
                       bool const& underline, bool const& strikeThrough) const
{
  // Régler la brosse pour le remplissage
  screen.setBrush(mFillColor.red(),
    mFillColor.green(),
    mFillColor.blue(),
    mFillColor.alpha());
  // Régler le crayon pour dessiner les segments
  screen.setPen(mOutlineColor.red(),
                mOutlineColor.green(),
                mOutlineColor.blue(),
                mOutlineColor.alpha(),
                lineWidth);
  // Régler les paramètres de la taille des caractères
  screen.setTextSizes(characterSize, letterSpacingRatio, lineSpacingRatio);
  // Régler les paramètres sur le format du texte
  screen.setTextStyle(bold, italic, underline, strikeThrough);
  // Tracer le texte à l'écran
  screen.drawText(text, x, y, rotation, scale);
}

// --------------------------------------------------------------------------------------
// Fonction(s) membre(s) utilitaire(s)
// --------------------------------------------------------------------------------------
// Conserver un chiffre après le point (la virgule) d'une chaîne de caractères représentant
// un nombre en virgule flottante. C'est pour simplifier l'affichage à l'écran.
std::string Polygon::strTo1Decimals(std::string const& inStr) // Transform a String to 1 decimal 
{
  // D'abord trouver le point dans la chaîne de caractères
  std::size_t commaPos = inStr.find('.');
  // Ensuite, faire une copie des caractères du début de la chaîne
  // jusqu'au premier caractère après le point.
  std::string sub1 = inStr.substr(0, commaPos+2);
  
  return sub1;
}
