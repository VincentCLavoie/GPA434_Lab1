/*  Spaceship.cpp
 *  Cette classe gère une forme polygonale représentante un viasseau spatial. Voici les éléments
 *  gérés par elle:
 *    - Sa forme polygone qui est particulière;
 *    - Sa vitesse (linéaire et angulaire);
 *    - Sa position (linéaire et angulaire);
 *    - Son accélération (linéaire et angulaire);
 *    - Sa distance parcourue;
 *    - Sa plus grande distance parcourue depuis le début du jeu;
 *    - Son dessin à l'écran par le biais de la classe Polygon.
 *
 *  ------------------------------------------------------------------------------------------
 *  GPA434 Laboratoire #1
 *  Cette classe est déjà réalisée en partie et les étudiants doit la compléter.
 *  ------------------------------------------------------------------------------------------
 *  Techniques à étudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment construire la forme polygonale représentant le vaisseau spatial;
 *    - Donner à un vaisseau spatial un comportement propre.
 *  ------------------------------------------------------------------------------------------
 *
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de données: PascalCase
 *    Variables, fonctions: camelCase
 */
#include "Spaceship.h"

// Constructeur avec paramètres
Spaceship::Spaceship(float origineX, float origineY)
	: mPosition(origineX, origineY),
	  mVelocity(),
	  mAcceleration(), 
	  mAngularPos{},
	  mAngularVel{},
	  mAngularAcc{},
	  mDistanceMade{},
	  mBestDistance{},
	  mShape()
{
	// Le vaisseau spatial aura la couleur noire, des traits blancs d'épaisseur de 1. Le point au centre
	// du vaisseau est à (0, 0).
	mShape.buildSpaceship(Color(1.0f, 1.0f, 0.0f, 1.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 0.0f, 0.0f);
}

// Destructeur
Spaceship::~Spaceship()
{
	// do nothing
}

// --------------------------------------------------------------------------------------
// Accesseur(s) et mutateur(s) (fonctions membres)
// --------------------------------------------------------------------------------------
Vect2d Spaceship::position() const
{
	// Retourner la position linéaire
	return mPosition;
}

Vect2d Spaceship::velocity() const
{
	// Retourner la vitesse linéaire
	return mVelocity;
}

Vect2d Spaceship::acceleration() const
{
	// Retourner l'accélération linéaire
	return mAcceleration;
}

float Spaceship::angularPos() const
{
	// Retourner la position angulaire
	return mAngularPos;
}

float Spaceship::angularVel() const
{
	// Retourner la vitesse angulaire
	return mAngularVel;
}

float Spaceship::angularAcc() const
{
	// Retourner l'accélération angulaire
	return mAngularAcc;
}

float Spaceship::distanceMade() const
{
	return mDistanceMade;
}

void Spaceship::setPosition(Vect2d const& position)
{
	// Assigner la position linéaire
	mPosition = position;
}

void Spaceship::setVelocity(Vect2d const& velocity)
{
	// Assigner la vitesse linéaire
	mVelocity = velocity;
}

void Spaceship::setAcceleration(Vect2d const& acceleration)
{
	// Assigner l'accélération linéaire
	mAcceleration = acceleration;
}

void Spaceship::setAngularPos(float const& angularPos)
{
	// Assigner la position angulaire
	mAngularPos = angularPos;
}

void Spaceship::setAngularVel(float const& angularVel)
{
	// Assigner la vitesse angulaire
	mAngularVel = angularVel;
}

void Spaceship::setAngularAcc(float const& angularAcc)
{
	// Assigner l'accélération angulaire
	mAngularAcc = angularAcc;
}

void Spaceship::resetAngularAcc()
{
	// RAZ: Assigner 0.0f à l'accélération angulaire
	mAngularAcc = 0.0f;
}

void Spaceship::resetVerticalPositionDown(float const& height)
{
	mPosition.setY(height);
}

void Spaceship::resetHorizontalPositionDown(float const& width)
{
	mPosition.setX(width);
}


void Spaceship::resetDistanceMade()
{
	// RAZ: Assigner 0.0f à la distance parcourue
	mDistanceMade = 0.0f;
}

// RAZ les attributs du vaisseau spatial (après une collision)
void Spaceship::resetSpaceship(float const& width, float const& height)
{
	// Repositionner le vaisseau au milieu de l'espace du jeu
	setPosition(Vect2d(width / 2, height / 2));
	// RAZ position angulaire
	setAngularPos(0.0f);
	// RAZ la distance parcourue
	resetDistanceMade();
	// Remettre la couleur de remplissage à noir
	mShape.setFill(Color(1.0f, 1.0f, 0.0f, 1.0f));
}

// --------------------------------------------------------------------------------------
// Mise à jour de la position et la vitesse linéaire du viasseau spatial
// Cette fonction membre est exécutée périodiquement par l'Engine du jeu.
//
// Note 1: d = vt + 1/2at^2 et v = at
// Note 2: On reçoit le temps écoulé depuis la dernière mise à jour. La nouvelle
//         position et la nouvelle vitesse sont obtenue en s'additionnant avec
//         leur valeur précédente.
// --------------------------------------------------------------------------------------
void Spaceship::processTime(float const& elapsedTime) // Update position vector 
{
	// 1) Calculer la nouvelle position linéaire
	//    Profitez du fait que Vect2d possède les opérateurs d'addition et de multiplication
	//    pour simplifier le codage.
	
	// 2) Calculer la nouvelle vitesse
	
	// 3) RAZ l'accélération linéaire car l’accélération
	//    est recalculée à chaque pas de temps par GameEngine
	
}


// --------------------------------------------------------------------------------------
// Mise à jour de la position et la vitesse angulaire du viasseau spatial
// Cette fonction membre est exécutée périodiquement par l'Engine du jeu.
//
// Note 1: d = vt + 1/2at^2 et v = at
// Note 2: On reçoit le temps écoulé depuis la dernière mise à jour. La nouvelle
//         position et la nouvelle vitesse sont obtenue en s'additionnant avec
//         leur valeur précédente.
// --------------------------------------------------------------------------------------
void Spaceship::angularProcessTime(float const& elapsedTime)
{
	// 1) Calculer la nouvelle position angulaire
	//    Profitez du fait que Vect2d possède les opérateurs d'addition et de multiplication
	//    pour simplifier le codage.
	
	// 2) Calculer la nouvelle vitesse angulaire
	
	// 3) RAZ l'accélération linéaire car l’accélération
	//    est recalculée à chaque pas de temps par GameEngine
	
}

// --------------------------------------------------------------------------------------
// Dessiner la forme polygonale dont le centre est au point mPosition.
// Cette fonction membre est normalement exécutée après la MAJ de la position.
// --------------------------------------------------------------------------------------
void Spaceship::draw(ezapp::Screen& screen) const
{
	// Utiliser l'objet mShape pour dessiner la forme polygonale à partir
	// de sa position linéaire et angulaire.

	
}

// --------------------------------------------------------------------------------------
// Cumuler la distance parcourue par le vaisseau spatial.
//
// Note 1: d = vt
// Note 2: La vitesse linéaire v est exprimée par rapport au plan cartésien X, Y et il
//         faut prendre sa norme pour calculer la distance parcourue.
// --------------------------------------------------------------------------------------
void Spaceship::distanceMade(float const& elapsedTime)
{
	// 1) Cumuler la distance parcourue seulement si la norme de
	//    vitesse est supérieure à une certainement valeur. C’est
	//    à dire que le vaisseau est effectivement en mouvement.
	if (mVelocity.norm() >= 5.0f)
	{
		// 2) Cumuler la distance parcourue par le vaisseau spatial.
	}
}

// --------------------------------------------------------------------------------------
// Afficher la distance parcourue dans l'espace du jeu.
// --------------------------------------------------------------------------------------
void Spaceship::drawDistanceMade(ezapp::Screen& screen) const
{
	Polygon distance;
	// 1) Former la chaîne de caractère contenant la distance parcourue.
	
	// 2) Donner les couleurs.
	
	// 3) Utiliser la fonction membre de l'objet Polygon pour dessiner la chaîne de caractère
	//    dans l'espace du jeu.
	
	
}

// --------------------------------------------------------------------------------------
// Afficher la plus grande distance parcourue dans l'espace du jeu.
// --------------------------------------------------------------------------------------
void Spaceship::drawBestDistance(ezapp::Screen& screen) const
{
	Polygon distance;
	// 1) Former la chaîne de caractère contenant la plus grande distance parcourue.

	// 2) Donner les couleurs.

	// 3) Utiliser la fonction membre de l'objet Polygon pour dessiner la chaîne de caractère
	//    dans l'espace du jeu.


}

// --------------------------------------------------------------------------------------
// Modifier les attributs du vaisseau spatial après une collision avec un asétroïde
//
// Note: Cette fonction membre NE DÉTECTE PAS une collision. Elle sert pluôt à gérer
//       le comportement du vaisseau spatial à la suite d'une collision avec un
//       astéroïde.
// --------------------------------------------------------------------------------------
void Spaceship::collison()
{
	// 1) Changer la couleur du vaisseau spatial pour indiquer une collision a eu lieu
	mShape.setFill(Color(1.0f, 0.0f, 0.0f));
	// 2) RAZ sa vitesse linéaire

	// 3) RAZ sa vitesse angulaire

	// 4) Mettre à jour la plus grande distance parcourue

}


