# Tetris in C++ / Qt

**Auteures : Maha Bouslimani, Lucile Maillot, Jamelia Kombila et Manel Babay.**
*Team project by Maha Bouslimani, Lucile Maillot, Jamelia Kombila, and Manel Babay.*

> A full Tetris game implemented in C++ with the Qt graphics library. The project goes from UML design (use case, class and sequence diagrams) all the way to a working desktop application with a graphical interface, seven tetromino shapes, rotations, line clearing, level progression, scoring, and customisable themes.
>
> Une implémentation complète du jeu Tetris en C++ avec la bibliothèque graphique Qt. Le projet couvre tout le cycle de développement, de la modélisation UML (diagrammes de cas d'utilisation, de classes et de séquences) jusqu'à une application de bureau fonctionnelle avec interface graphique, sept formes de tétrominos, rotations, suppression de lignes, progression des niveaux, système de score et thèmes personnalisables.

---

[English](#english) | [Français](#français)

---

## English

### Overview

Tetris is a classic puzzle game created in 1984 by Alexey Pajitnov, in which the player arranges falling geometric pieces (tetrominoes) inside a well to form complete horizontal lines. This project reimplements the full game in C++ and Qt, with a strong focus on object-oriented design. The development was driven by UML modelling (use case, class and sequence diagrams) before any line of code was written, and the resulting architecture relies on inheritance, polymorphism, and encapsulation to keep the code modular and extensible.

The project was carried out between September 30, 2025 and February 20, 2026.

### Game rules

- The well is a grid of 10 columns by 22 rows. Tetrominoes spawn at the top and fall cell by cell.
- The player can move the current piece left or right, rotate it by 90 degrees, or accelerate its descent.
- A piece locks in place as soon as it touches the bottom of the well or the top of another piece.
- Any row entirely filled with cells disappears, and everything above it shifts one row down.
- The game ends when the stack reaches the top of the well.

### Scoring and progression

The score increases when rows are cleared. A single row gives 40 points, two rows at once give 100 points, three rows give 300 points, and four rows at once (a Tetris) give 1 200 points. The base score is then multiplied by the current level according to the formula F(p, n) = p * (n + 1), where p is the base number of points and n is the level. Each level increases the falling speed of the pieces, which is the main difficulty driver.

### Tetromino shapes

The game uses the seven standard tetrominoes, each in four rotation states and with its own colour:

| Piece | Colour |
|-------|--------|
| I | Red |
| O | Blue |
| T | Brown |
| S | Green |
| Z | Cyan |
| L | Magenta |
| J | Grey |

### Features

- Seven tetromino types with four rotation states each
- Collision detection against the walls, the floor, and already locked pieces
- Line clearing with cascade shift of the rows above
- Preview of the next piece, live score, current level, and elapsed time
- Keyboard controls for movement, rotation, and soft drop
- End-of-game detection with final score
- Menus with dialogs for rules, controls, level selection, and themes

### Project structure

```
├── include/              Header files
│   ├── objetgraphique.h  Base class for every drawable object
│   ├── Tetromino.h       Abstract base class for all tetrominoes
│   ├── i.h, j.h, l.h, o.h, s.h, t.h, z.h
│   │                     The seven tetromino subclasses
│   ├── puits.h           The well (game board)
│   ├── partie.h          Game session (score, level, loop state)
│   ├── mainwindow.h      Main Qt window
│   └── dialog*.h         Dialogs for rules, controls, levels, themes
├── src/                  Matching .cpp implementations
├── ui/                   Qt Designer .ui files for the main window and dialogs
├── fonts/                Custom fonts used by the interface
├── ressources/           Images and graphical assets
├── PROJET2.pro           Qt project file
├── LICENSE
└── README.md
```

### How to build and run

Requirements: a C++ compiler and Qt 5 or Qt 6 with Qt Creator.

1. Clone the repository:

   ```bash
   git clone https://github.com/jokombila/tetris-game.git
   cd tetris-game
   ```

2. Open `PROJET2.pro` in Qt Creator.

3. Select a kit (desktop, Qt 5 or Qt 6) and click **Build**, then **Run**.

Alternatively, on the command line:

```bash
qmake PROJET2.pro
make
./PROJET2
```

### Implementation

- Pure object-oriented design with a base class `ObjetGraphique`, an abstract class `Tetromino`, and seven concrete tetromino subclasses (`I`, `J`, `L`, `O`, `S`, `T`, `Z`)
- Each tetromino holds four cells in local coordinates and a reference anchor in the well, giving a double-coordinate system that simplifies rotation and translation
- Collision detection based on a projected test of the future cell positions before any movement or rotation is committed
- Rotation state machine with four positions per tetromino and rollback if the rotated piece collides with a wall or another piece
- Line clearing algorithm that scans the well from bottom to top, removes full rows, and cascades the upper rows down
- Random tetromino generation using the C++ standard library
- Event handling via Qt keyboard events for movement, rotation and soft drop
- Main loop driven by a `QTimer` whose interval decreases with the level
- Graphical rendering with `QPainter` inside the main widget, with themes selectable through a dedicated dialog
- UML-first workflow: use case diagram, class diagram, and sequence diagrams were produced before implementation to fix the architecture

---

## Français

### Auteures

Auteures : Maha Bouslimani, Lucile Maillot, Jamelia Kombila et Manel Babay.
Projet réalisé du 30 septembre 2025 au 20 février 2026.

### Présentation

Tetris est un jeu de puzzle classique créé en 1984 par Alexey Pajitnov, dans lequel le joueur agence des pièces géométriques (les tétrominos) qui tombent dans un puits afin de former des lignes horizontales complètes. Ce projet réimplémente le jeu entièrement en C++ avec la bibliothèque graphique Qt, avec un accent fort sur la conception orientée objet. Le développement a été guidé par une modélisation UML (diagrammes de cas d'utilisation, de classes et de séquences) avant toute ligne de code, et l'architecture qui en découle repose sur l'héritage, le polymorphisme et l'encapsulation pour garder un code modulaire et extensible.

### Règles du jeu

- Le puits est une grille de 10 colonnes sur 22 lignes. Les tétrominos apparaissent en haut et tombent case par case.
- Le joueur peut déplacer la pièce courante à gauche ou à droite, la faire pivoter de 90 degrés, ou accélérer sa chute.
- Une pièce se fixe dès qu'elle touche le bas du puits ou le sommet d'une autre pièce.
- Toute ligne entièrement remplie disparaît, et tout ce qui se trouve au-dessus descend d'un cran.
- La partie se termine lorsque la pile atteint le haut du puits.

### Score et progression

Le score augmente lorsque des lignes sont complétées. Une ligne rapporte 40 points, deux lignes simultanées en rapportent 100, trois lignes 300, et quatre lignes simultanées (un Tetris) 1 200 points. Ce score de base est ensuite multiplié par le niveau courant selon la formule F(p, n) = p * (n + 1), où p est le nombre de points de base et n le niveau. Chaque niveau accélère la vitesse de chute des pièces, ce qui constitue le principal moteur de difficulté.

### Formes des tétrominos

Le jeu utilise les sept tétrominos standards, chacun avec quatre états de rotation et sa propre couleur :

| Pièce | Couleur |
|-------|---------|
| I | Rouge |
| O | Bleu |
| T | Brun |
| S | Vert |
| Z | Cyan |
| L | Magenta |
| J | Gris |

### Fonctionnalités

- Sept types de tétrominos avec quatre états de rotation chacun
- Détection des collisions contre les murs, le sol et les pièces déjà fixées
- Suppression de lignes avec cascade des lignes supérieures
- Aperçu de la prochaine pièce, score en direct, niveau courant, et temps écoulé
- Contrôles clavier pour le déplacement, la rotation et la descente rapide
- Détection de fin de partie avec score final
- Menus avec boîtes de dialogue pour les règles, les commandes, le choix du niveau et les thèmes

### Structure du projet

```
├── include/              Fichiers d'en-tête
│   ├── objetgraphique.h  Classe de base pour tout objet dessinable
│   ├── Tetromino.h       Classe abstraite de base des tétrominos
│   ├── i.h, j.h, l.h, o.h, s.h, t.h, z.h
│   │                     Les sept sous-classes de tétrominos
│   ├── puits.h           Le puits (plateau de jeu)
│   ├── partie.h          Session de jeu (score, niveau, état de la boucle)
│   ├── mainwindow.h      Fenêtre principale Qt
│   └── dialog*.h         Dialogues pour les règles, commandes, niveaux, thèmes
├── src/                  Implémentations .cpp correspondantes
├── ui/                   Fichiers .ui de Qt Designer pour la fenêtre et les dialogues
├── fonts/                Polices personnalisées de l'interface
├── ressources/           Images et ressources graphiques
├── PROJET2.pro           Fichier projet Qt
├── LICENSE
└── README.md
```

### Compilation et exécution

Prérequis : un compilateur C++ et Qt 5 ou Qt 6 avec Qt Creator.

1. Cloner le dépôt :

   ```bash
   git clone https://github.com/jokombila/tetris-game.git
   cd tetris-game
   ```

2. Ouvrir `PROJET2.pro` dans Qt Creator.

3. Choisir un kit (desktop, Qt 5 ou Qt 6), puis cliquer sur **Build** puis **Run**.

En ligne de commande :

```bash
qmake PROJET2.pro
make
./PROJET2
```

### Réalisation

- Conception orientée objet avec une classe de base `ObjetGraphique`, une classe abstraite `Tetromino`, et sept sous-classes concrètes (`I`, `J`, `L`, `O`, `S`, `T`, `Z`)
- Chaque tétromino contient quatre cases en coordonnées locales ainsi qu'un ancrage de référence dans le puits, donnant un système à double coordonnées qui simplifie la rotation et la translation
- Détection des collisions par test projeté des futures positions des cases avant d'appliquer un déplacement ou une rotation
- Machine à états de rotation avec quatre positions par tétromino et retour arrière si la pièce pivotée entre en collision avec un mur ou une autre pièce
- Algorithme de suppression de lignes qui parcourt le puits de bas en haut, retire les lignes pleines et fait descendre en cascade les lignes supérieures
- Génération aléatoire des tétrominos avec la bibliothèque standard C++
- Gestion des événements via les événements clavier Qt pour le déplacement, la rotation et la descente rapide
- Boucle principale pilotée par un `QTimer` dont l'intervalle diminue avec le niveau
- Rendu graphique avec `QPainter` dans le widget principal, avec thèmes sélectionnables via une boîte de dialogue dédiée
- Démarche UML en amont : diagramme de cas d'utilisation, diagramme de classes, et diagrammes de séquences produits avant l'implémentation pour fixer l'architecture

### Auteures

Projet réalisé par **Maha Bouslimani**, **Lucile Maillot**, **Jamelia Kombila** et **Manel Babay** (2025/2026).
GitHub : [@jokombila](https://github.com/jokombila)

---

## License / Licence

All rights reserved. This source code is made publicly available for portfolio and demonstration purposes only. No part of this project may be copied, modified, distributed, or reused without the prior written permission of the authors. See [LICENSE](LICENSE) for the full terms.

Tous droits réservés. Ce code source est mis à disposition publique à des fins de portfolio et de démonstration uniquement. Aucune partie de ce projet ne peut être copiée, modifiée, distribuée ou réutilisée sans l'autorisation écrite préalable des auteures. Voir [LICENSE](LICENSE) pour les termes complets.
