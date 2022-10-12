/*  Spaceship.cpp
 *  Cette classe gère une forme polygonale représentante un viasseau spatial. Voici les éléments
 *  gérés par elle:
 *    - Sa forme polygone qui est particulière;
 *    - Sa vitesse (linéaire et angulaire);
 *    - Sa position (linéaire et angulaire);
 *    - Son accélération (linéaire et angulaire);
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
	mShape(),
	mShapeMissile(),
	mMissile(-1.0f, -1.0f),
	vitesseMissile(-1, -1)
{
	// Le vaisseau spatial aura la couleur noire, des traits blancs d'épaisseur de 1. Le point au centre
	// du vaisseau est à (0, 0).
	mShape.buildSpaceship(Color(1.0f, 1.0f, 0.0f, 1.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 0.0f, 0.0f);
	mShapeMissile.buildMissile(Color(0.6f, 1.0f, 0.0f, 1.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 0.0f, 0.0f);
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
	mPosition += mVelocity * elapsedTime + 0.5 * (mAcceleration) * (elapsedTime * elapsedTime);

	// 2) Calculer la nouvelle vitesse
	mVelocity += mAcceleration * elapsedTime;

	// 3) RAZ l'accélération linéaire car l’accélération
	//    est recalculée à chaque pas de temps par GameEngine
	mAcceleration = 0;
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
	mAngularPos += mAngularVel * elapsedTime + 0.5 * mAngularVel * (elapsedTime * elapsedTime);

	// 2) Calculer la nouvelle vitesse angulaire
	mAngularVel += mAngularAcc * elapsedTime;

	// 3) RAZ l'accélération linéaire car l’accélération
	//    est recalculée à chaque pas de temps par GameEngine
	mAngularAcc = 0;
}

// --------------------------------------------------------------------------------------
// Dessiner la forme polygonale dont le centre est au point mPosition.
// Cette fonction membre est normalement exécutée après la MAJ de la position.
// --------------------------------------------------------------------------------------
void Spaceship::draw(ezapp::Screen& screen) const
{
	// Utiliser l'objet mShape pour dessiner la forme polygonale à partir
	// de sa position linéaire et angulaire.

	mShape.draw(screen, mPosition.x(), mPosition.y(), mAngularPos);
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
		mDistanceMade += mVelocity.norm() * elapsedTime;
	}
}

// --------------------------------------------------------------------------------------
// Afficher la distance parcourue dans l'espace du jeu.
// --------------------------------------------------------------------------------------
void Spaceship::drawDistanceMade(ezapp::Screen& screen) const
{
	Polygon distance;
	// 1) Former la chaîne de caractère contenant la distance parcourue.
	std::string msg = "Distance Parcouru: " + std::to_string(mDistanceMade);

	// 2) Donner les couleurs.
	distance.setColors(Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f));

	// 3) Utiliser la fonction membre de l'objet Polygon pour dessiner la chaîne de caractère
	//    dans l'espace du jeu.
	distance.drawText(screen, msg, 20.0f, 55.0f, 0.0f, 0.7f);

}

/*Écrire l'écran de fin de partie*/
void Spaceship::drawGameOverScreen(ezapp::Screen& screen) const
{
	Polygon GameOverString;
	// 1) Former la chaîne de caractère contenant la distance parcourue.
	std::string msg = "Ah, vous ne vous êtes même pas rendu à " + std::to_string(floor(mDistanceMade))
		+ "\nCliquez sur espace pour recommencer le jeu.";

	// 2) Donner les couleurs.
	GameOverString.setColors(Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f));

	// 3) Utiliser la fonction membre de l'objet Polygon pour dessiner la chaîne de caractère
	//    dans l'espace du jeu.
	GameOverString.drawText(screen, msg, 200.0f, 200.0f, 0.0f, 0.7f);
}

// --------------------------------------------------------------------------------------
// Afficher la plus grande distance parcourue dans l'espace du jeu.
// --------------------------------------------------------------------------------------
void Spaceship::drawBestDistance(ezapp::Screen& screen) const
{
	Polygon distance;
	// 1) Former la chaîne de caractère contenant la plus grande distance parcourue.
	std::string msg = "Meilleur distance Parcouru: " + std::to_string(mBestDistance);

	// 2) Donner les couleurs.
	distance.setColors(Color(1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f));

	// 3) Utiliser la fonction membre de l'objet Polygon pour dessiner la chaîne de caractère
	//    dans l'espace du jeu.
	distance.drawText(screen, msg, 20.0f, 75.0f, 0.0f, 0.7f);

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
	mVelocity = 0;

	// 3) RAZ sa vitesse angulaire
	mAngularVel = 0;

	// 4) Mettre à jour la plus grande distance parcourue
	mBestDistance = mDistanceMade;
}

bool Spaceship::missileShot() const
{
	return mMissile.missileShot();		// Retourne l’état du missile (tiré, non tiré)
}

void Spaceship::resetMissileShot(bool const& missileShot)
{
	// 1) Règle l'état du missile
	mMissile.setMissileShot(missileShot);
	// 2) RAZ la position du missile
	mMissile.setPosition(Vect2d(-10.0f, -10.0f));
}

void Spaceship::manageMissile(bool const& spaceBarPressed, float const& elapsedTime)
{
	const float missileVel = 150.0f; // Module de la vitesse du missile
	//Vect2d norm;
	//Vect2d angle;

	// 1) Si la touche SPACEBAR est appuyée et que le missile est disponible à tirer...
	if (spaceBarPressed == true and mMissile.missileShot() == false)
	{
		// 1.1) Règle l'état du missile à « tiré »
		mMissile.setMissileShot(true);

		// 1.2) Règle la position linéaire du missile (même que celle du vaisseau spatial)
		mMissile.setPosition(mPosition);  //mPosition du Spaceship?

		// 1.3) Règle la position angulaire du missile (même que celle du vaisseau spatial)
		mMissile.setAngularPos(mAngularPos); // AngPos du Spaceship?
		vitesseMissile.setFromPolar(missileVel, mMissile.angularPos() - (90.0f * 3.141592654f)/180.0f);

		// 1.4) Calculer la vitesse du missile et l'assigner au missile
		mMissile.setVelocity(vitesseMissile);
	}
	// 2) Si le missile a été tiré
	if (mMissile.missileShot() == true)
	{
		// Alors mettre à jour la position du missile
		mMissile.processTime(elapsedTime);
	}
}

void Spaceship::drawMissile(ezapp::Screen& screen) const
{
	mShapeMissile.draw(screen, mMissile.position().x(), mMissile.position().y(), mMissile.angularPos());
	// Dessiner le missile
}




void Spaceship::drawNbMissile(ezapp::Screen& screen,
	float const& width) const
{
	/************************************************/
	// Dessiner une indication visuelle pour signifier
	// au joueur qu’il peut tirer à nouveau
}

Vect2d Spaceship::positionMissile() const
{
	// Retourner la position linéaire du missile
	return mMissile.position();
}

void Spaceship::collisionMissileWall() 
{
	mMissile.collison();
}