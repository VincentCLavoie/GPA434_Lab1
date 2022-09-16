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
#include "Polygon.h"
#include <algorithm>

// Constructeur par d�faut
Polygon::Polygon()
    : mVertex(3),                           // minimum trois sommets pour un polygone ferm�
    mFillColor(1.0f, 1.0f, 1.0f, 1.0f),     // valeur RGB et transparence
    mOutlineColor(1.0f, 1.0f, 1.0f, 1.0f),
    mOutlineWidth{ 1.0f }                   // �paisseur des segments
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
// Ainsi, un objet de type Polygon sait comment d�finir ses sommets pour donner les
// formes ci-dessous.
// --------------------------------------------------------------------------------------

// Pour cette �tape, on construire un ast�ro�de
void Polygon::buildasteroid(float const& summitCount, Color const& inside, Color const& outline, float const& outlineWidth)
{
  // � implanter (voir le document "GPA434_Lab1_D�marrage_Rapide.pdf")

}


// --------------------------------------------------------------------------------------
// Tra�age � l'�cran
// Ainsi, un objet Polygon sait comment tracer ses segments, sous forme graphique, sur
// l'�cran de EzApp.
// --------------------------------------------------------------------------------------
void Polygon::draw(ezapp::Screen& screen, float const& x, float const& y,
                   float const& rotation, float const& scale) const
{
  // R�gler la brosse pour le remplissage
  screen.setBrush(mFillColor.red(),
                  mFillColor.green(),
                  mFillColor.blue(),
                  mFillColor.alpha());
  // R�gler le crayon pour dessiner les segments
  screen.setPen(mOutlineColor.red(),
                mOutlineColor.green(),
                mOutlineColor.blue(),
                mOutlineColor.alpha(),
                mOutlineWidth);
  // R�gler les sommets du polygone dans l'�cran
  screen.setPolygonVertices(mVertex);
  // Tracer le polygone � l'�cran
  screen.drawPolygon(x, y, rotation, scale);

}

void Polygon::drawText(ezapp::Screen& screen, std::string const& text, float const& x,
                       float const& y, float const& rotation, float const& scale,
                       float const& lineWidth, size_t characterSize, float const& letterSpacingRatio,
                       float const& lineSpacingRatio, bool const& bold, bool const& italic,
                       bool const& underline, bool const& strikeThrough) const
{
  // R�gler la brosse pour le remplissage
  screen.setBrush(mFillColor.red(),
    mFillColor.green(),
    mFillColor.blue(),
    mFillColor.alpha());
  // R�gler le crayon pour dessiner les segments
  screen.setPen(mOutlineColor.red(),
                mOutlineColor.green(),
                mOutlineColor.blue(),
                mOutlineColor.alpha(),
                lineWidth);
  // R�gler les param�tres de la taille des caract�res
  screen.setTextSizes(characterSize, letterSpacingRatio, lineSpacingRatio);
  // R�gler les param�tres sur le format du texte
  screen.setTextStyle(bold, italic, underline, strikeThrough);
  // Tracer le texte � l'�cran
  screen.drawText(text, x, y, rotation, scale);
}

// --------------------------------------------------------------------------------------
// Fonction(s) membre(s) utilitaire(s)
// --------------------------------------------------------------------------------------
// Conserver un chiffre apr�s le point (la virgule) d'une cha�ne de caract�res repr�sentant
// un nombre en virgule flottante. C'est pour simplifier l'affichage � l'�cran.
std::string Polygon::strTo1Decimals(std::string const& inStr) // Transform a String to 1 decimal 
{
  // D'abord trouver le point dans la cha�ne de caract�res
  std::size_t commaPos = inStr.find('.');
  // Ensuite, faire une copie des caract�res du d�but de la cha�ne
  // jusqu'au premier caract�re apr�s le point.
  std::string sub1 = inStr.substr(0, commaPos+2);
  
  return sub1;
}
