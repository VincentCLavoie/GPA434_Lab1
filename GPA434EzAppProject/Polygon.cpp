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

void Polygon::buildSpaceship(Color const& inside, Color const& outLine, float const& x,
    float const& y, float const& outlineWidth)
{
    // R�gler la couleur de remplissage, couleur des segments et
    // la largeur des segments.
    setColors(inside, outLine, outlineWidth);
    // R�server le nombre de sommets
    mVertex.resize(6);
    // Indiquer les coordonn�es des sommets dans l'ordre.
    mVertex[0].set(x, y - 35.0f);
    mVertex[1].set(x - 37.7f, y + 9.9f);
    mVertex[2].set(x - 31.6f, y + 15.0f);
    mVertex[3].set(x + 31.6f, y + 15.0f);
    mVertex[4].set(x + 37.7f, y + 9.9f);
    mVertex[5].set(x, y - 35.0f);
    
}


// Pour cette �tape, on construire un ast�ro�de
void Polygon::buildasteroid(float const& summitCount, Color const& inside, Color const& outline, float const& outlineWidth)
{
    setColors(inside, outline, outlineWidth);
    mVertex.resize(std::max((size_t)5, (size_t)summitCount));
    // On utilise les coordonn�es polaires (norme, theta) d'un Vect2d pour construire l'ast�ro�de
    // La forme irr�guli�re de l'ast�ro�de est obtenue gr�ce � l'utilisation de fonction al�atoire
    // rand() dans la g�n�ration des Vect2d.
    //
    // Contrainte: Chaque Vect2d aura une norme variant entre 10 � 30 unit�s et un angle theta
    //
    for (size_t i{}; i < mVertex.size(); ++i) {
        mVertex[i].setFromPolar((float)rand() / (float)RAND_MAX * (30 - 10) + 10, i * 2.0f * 3.141592654f /
            mVertex.size());
    }
}


// Pour cette �tape, on construire un missile.
void Polygon::buildMissile(Color const& inside, Color const& outLine, float const& x,
    float const& y, float const& outlineWidth)
{
    setColors(inside, outLine, outlineWidth);
    // R�server le nombre de sommets
    mVertex.resize(13);
    // Indiquer les coordonn�es des sommets dans l'ordre.
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
