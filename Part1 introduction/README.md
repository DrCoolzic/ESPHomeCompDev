Développement d’un Composant ESPHome Partie 1 : Introduction 
# **Présentation** 
La vocaon première d’ESPHome est de permetre la craon de **modules** lectroniques par des ulisateurs *qui n’ont aucune connaissance en informatique*. Pour cela il fait appel à une bibliothèque de **composants** qu’il assemble en foncon des demandes de l’ulisateur et gnère automaquement pour lui le code ncessaire pour raliser la foncon souhait e. Ensuite l’ulisateur n’a qu’ à assembler sur une carte lectronique les diffrents composants dont il a besoin . Il faut ensuite la connecter à un ordinateur pour charger le code gnr é par ESPHome. 

Une prcision concernant la terminologie ulis e  : 

- Un « **module** » (**device**) sert à désigner un ensemble de **composants** grouper par un ulisateur  pour raliser une foncon . Dans ESPHome la descripon d’ un module est dfini e dans un fichier yaml. Par exemple on peut dfinir un module pour mesurer la temprature d’une pièce. Pour cela on va ulise r un microcontrôleur ESP32 qui sera connecté par un bus I²C à un capteur de temprature. 
- Un « composant » (**component**) sert à dsigner un lment de base de  la bibliothèque d’ESPHome. Les composants peuvent être des composants physiques comme par exemple un capteur, ou des composants logiques comme par exemple un bus I²C. Un composant est 

dfini par un ensemble de fichiers en langage C++ et langage Python. 

Un **ulisateur** normal d’ESPHome cre de nouveaux **modules.** Les modules sont dcrits dans  un fichier de configuraon Yaml et à parr de cete descripon le programme ESPHome gnère automaquement  du code C++. Ce code est compil et un excutable est gnr. L e firmware rsultant est  charg dans la mmoire du microcontrôleur et son excuon est lance . 

Un **dveloppeur** pour ESPHome va lui crer  de nouveaux **composants** pour la bibliothèque. C’est une opraon  beaucoup plus complexe car elle ncessite que le dveloppeur dcrive le fonconnement 

du composant en ulisant les langages  C++ et Python. Cela requiert une bonne connaissance du langage C++, et des noons de base du langage Python. 

J’ai t confront au problème de crer un  **module[ ESPHome ](https://esphome.io/)**qui ulis ait des **composants** qui *n’existaient pas* dans la **bibliothèque** d[’ESPHome.](https://esphome.io/) Et donc je me suis pos la queson de savoir quelle procdure et quels ouls uliser pour crer  ce nouveau composant. 

À ma connaissance il existe beaucoup de tutoriels sur la craon de modules  dans ESPHome mais très peu sur la craon de nouveau x composants. J’ai donc procd par tâtonnements avec l’aide d’autres ulisateurs et a u final je me suis dfini un environnement et un processus à suivre. Comme j’ai appris pas mal de choses durant ce cheminement j’ai pens qu’il serait intressant de partager cete exprience. Je prcise que je prsente ici  la façon dont moi je procède, mais il existe videmment d’autres façons de procder . 
# **Vision à haut niveau d’ESPHome** 
Je vais d’abord vous prsenter le fonconnement d’ESPHome à un haut niveau d’abstracon tel que je le comprends. 

Pour crer un nouveau **module** dans ESPHome, vous devez dfinir tous les composants que vous souhaitez uliser  et comment les interconnects .  

Par exemple pour crer un module de « mesure de temprature dans une pièce » vous allez indiquer que vous voulez uliser : un microcontrôleur ESP32 install sur  une carte de dveloppement esp32dev connect à un capteur BMP085 au travers d’un bus I²C.  

Le capteur mesure la temprature et  la retourne à Home Assistant au travers de l’API nave d’ESPHome en Wifi.  

Le fichier Yaml va ressembler à cela :  

esphome : ![](Aspose.Words.ba756ba1-6647-4320-8f7e-f3df186b8a01.001.png)

`  `name: test-bmp085   platform : esp32   board: esp32dev 

api : 

wifi : 

`  `ssid: !secret wifi\_ssid 

`  `password: !secret wifi\_password 

i2c: 

`  `sda: 21 

`  `scl: 22 

`  `id: bus\_i2c\_id 

sensor: 

\- platform: bmp085 

`    `i2c\_id : bus\_i2c 

`    `address: 0x77 

`    `temperature: 

`      `name: "Outside Temperature" 

Dans ce fichier on indique qu’on cre un  nouveau module ESPHome appel « test-bpm085 », que le microprocesseur ulis est un « ESP32 », lequel est mont sur une carte de 

dveloppement « esp32dev », que le module se connecte à votre rseau « Wi-Fi », qu’il communique avec Home Assistant grâce au « protocole api naf », qu’il ulise  un bus « I2C », et qu’un « capteur BMP085 » connect a u bus I²C pour retourne la temprature. 

À parr de cete descripon la *magie* d’ESPHome opère en excut ant les tâches suivantes : 

- Dans un premier temps ESPHome va lire le fichier Yaml. Ce qui lui permet d’numrer tous les composants uliss et de connaitre toutes les interconnexions (craon  interne d’une netlist). Dans cete phase une vrificaon de la syntaxe et de la smanque du fichier Yaml est effectue. 

C’est la phase dite de prpar aon et de vrificaon.

- Dans un deuxième temps, ESPHome va rechercher dans sa bibliothèque tous les composants qui sont uliss dans ce module. Par exemple : un composant wifi, un composant I2C, un composant Api, un composant BMP085, un composant capteur, etc. Il copie alors le code source de ces composants dans un rpertoire  crer  spcifiquement  pour le module en cours d’assemblage. Afin « d’instancier » et « de connecter » les composants entre eux, à parr de la netlist , il gnère un fichier en C++ (main.cpp). C’est la phase de gnraon d e code. Au cours de cete phase, ESPHome gnère galement tout  l’environnement ncessaire à PlaormIO . Il lance ensuite PlaormIO  qui va se charger de crer , tlcharger , et lancer l’excuon du firmware r sultant sur la cible matrielle.  

Ce diagramme dcrit le processus : 

Yaml![](Aspose.Words.ba756ba1-6647-4320-8f7e-f3df186b8a01.002.png)

Config ESPHome  PlatformIO

Comp. DB environment

Custom Comp. Code

**ESPHome PlatformIO**

Target device

PlatformIO project

Donc pour rsumer , après validaon du fichier de configuraon,  les fichiers sources des diffrents composants uliss  sont copis dans le projet  PlaormIO , un fichier main.cpp ainsi que le fichier plaformio.ini sont gnrs et le contrôle est passé à PlaormIO . 

PlaormIO  vrifie que l’environnement de dveloppement ncessaire, tel que les compilateurs, les bibliothèques, les ulitaires de progr ammaon, etc . sont bien prsents et à jour . Cet environnement est spcifi dans le fichier de configuraon **platformio.ini** gnr par ESPHome.  PlaormIO va ensuite compiler et tlcharger le code rsultant dans l’appareil cible.

Dans cette série de présentations nous allons nous intéresser non pas à l‛utilisation mais à la création de composants qui pourront par la suite être utilisés pour créer de nouveaux modules.  

Le processus commence par : 

- l’criture d’une documentaon qui indiquera à  l’ulisateur comment ulis er notre nouveau composant.  
- l’criture de fichiers Python pour valider le module  et gnrer du code C++  à parr de la configuraon ulisateur. 
- L’criture de fichiers C++ pour « modliser  » le composant. Cete pare du dveloppement est la plus longue et la plus complexe car elle ncessite d’analyser en dtail les spcificaon s du composant, de comprendre un minimum l’architecture interne d’ESPHome, et d’crire le code qui modlise fonconnellement le composant.
- La soumission de votre nouveau composant à la bibliothèque d’ESPHome. C’est une phase parfois longue et difficile car le code et la documentaon pour les composants d’ESPHome doivent respecter des contraintes très strictes. Cete phase ncessite de dialoguer avec l a personne en charge de la validaon de votre composant… 
- Bien que cela ne soit menonn nulle part, j e pense que lorsque vous ajoutez un nouveau composant à ESPHome il est implicitement entendu que vous vous engagez à maintenir ce composant (bug-fix et enhancement). Pour cela votre nom de dveloppeur GitHub est associ au composant. 

Mais avant tout cela il faut commencer par installer l’environnement de dveloppement… 
