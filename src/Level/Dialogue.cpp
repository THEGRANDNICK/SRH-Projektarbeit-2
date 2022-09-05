#include "Dialogue.h"

/*
DialogueNode::DialogueNode(string Text) {
  text = Text;
}

DialogueOption::DialogueOption(string Text, int ReturnCode, DialogueNode *NextNode) {
  text = Text;
  returnCode = ReturnCode;
  nextNode = NextNode;
}

//Constructor!
Dialogue::Dialogue()
{

}

//sets up the tree
void Dialogue::init()
{

  /*const char message[128] = "This sample illustrates a text writing\nanimation effect! Check it out! ;)";
  int framesCounter = 0;

  if (IsKeyDown(KEY_SPACE)) framesCounter += 8;
  else framesCounter++;

  if (IsKeyPressed(KEY_ENTER)) framesCounter = 0;

  DialogueNode *node0 = new DialogueNode("Welcome Nemo, I'm guessing this is your first time-travel?");
  //DialogueNode *node0 = new DialogueNode("Welcome Nemo, I'm guessing this is your first time-travel?");
  DialogueNode *node1 = new DialogueNode("Then dont get any help from me you twat!");
  DialogueNode *node2 = new DialogueNode("I'm Epanox a Time Guardian...");
  DialogueNode *node3 = new DialogueNode("No I can't send you back because you are the one who's travelled through time, in order for you to travel back home you need to find the time crystals hidden in the dungeon.");
  DialogueNode *node4 = new DialogueNode("You are currently in egypt, 2490 B.C");
  DialogueNode *node5 = new DialogueNode("In oder for you to return home you need to collect time crystals hidden in the dungeon, but be warned there are enemy's in that dungeon as well.");

  //Node 0
  node0->dialogueOptions.push_back(DialogueOption("Yes, who are you?", 0, node2));
  node0->dialogueOptions.push_back(DialogueOption("No, Fuck OFF!", 0, node1));
  dialogueNodes.push_back(node0);

  //Node 1
  node1->dialogueOptions.push_back(DialogueOption("Then dont get any help from me you twat! ", 0, nullptr));
  dialogueNodes.push_back(node1);

  //Node 2
  node2->dialogueOptions.push_back(DialogueOption("A Time Guardian? Does that mean you can send me back?", 0, node3));
  node2->dialogueOptions.push_back(DialogueOption("Where am I/ When am I?", 0, node4));
  node2->dialogueOptions.push_back(DialogueOption("How do I get home?", 0, node5));
  dialogueNodes.push_back(node2);

  //Node 3
  node3->dialogueOptions.push_back(DialogueOption("Where am I/ When am I?", 0, node4));
  node3->dialogueOptions.push_back(DialogueOption("Got it i'll go on, thanks for the help.", 0, nullptr));
  dialogueNodes.push_back(node3);

  //Node 4
  node4->dialogueOptions.push_back(DialogueOption("Egypt, damn I've always wanted to travel here, Ill be on my way, thanks...", 1, nullptr));
  node4->dialogueOptions.push_back(DialogueOption("No way, how do I get home?!.", 0, node5));
  dialogueNodes.push_back(node4);

  //Node 5
  node5->dialogueOptions.push_back(DialogueOption("Ok thanks for tip, I'll be off then!", 1, nullptr));
  dialogueNodes.push_back(node5);
  }

void Dialogue::destroyDialogue()
{
  for (int i = 0; i < dialogueNodes.size(); i++) {
    delete dialogueNodes[i];
  }
  dialogueNodes.clear();
}
//does the actual conversation and returns the outcome
int Dialogue::performDialogue()
{ if (dialogueNodes.size() == 0) {
    return - 1;
  }

  DialogueNode *currentNode = dialogueNodes[0];
  
  while (true){
    
    cout << currentNode->text << "\n\n";

    for (int i = 0; i < currentNode->dialogueOptions.size(); i++) {
      cout << i + 1 << ": "<< currentNode->dialogueOptions[i].text << endl;
    }
    cout << endl;
    int input;
    cin >> input;
    input--;

    if (input < 0 || input > currentNode->dialogueOptions.size()){
      cout << "Invalid input!\n";
    } else {
      // check for end of conversation
      if (currentNode->dialogueOptions[input].nextNode == nullptr) {
        return currentNode->dialogueOptions[input].returnCode;
      };

      currentNode = currentNode->dialogueOptions[input].nextNode;

    }
    cout << endl;
  }
  return 0;
}
void Dialogue::start() {
  DrawText("Welcome to Custodia", 958, 593 , 10, BLACK);
}
*/
Game::Dialog::Dialog() {}

void Game::Dialog::DialogStart() {
  //DrawTextEx("FontType", "",text_position, 20.0, 0, WHITE);
  //DrawText("Welcome to Narnia", text_position.x, text_position.y,30,WHITE);

  /*std::fstream dialog_txt_file;

  // open a file to perform read operation using file
  dialog_txt_file.open("assets/dialog_test_text.txt", std::ios::in);

  // checking whether the file is open
  if (dialog_txt_file.is_open()) {
    if (IsKeyPressed(KEY_SPACE)) {
      std::string text;
      while (getline(dialog_txt_file, text)) { // read data from file object and put it into string.
        std::cout << text << "\n"; //print the data of the string
        //DrawText(text, text_position.x, text_position.y, 10, WHITE);
      }
      dialog_txt_file.close(); // close the file object.
    }
  }*/

  textState = 0;

  if (IsKeyPressed(KEY_SPACE) && textState == 0) {
    textState = 1;
  }
  else if (IsKeyPressed(KEY_SPACE) && textState == 1) {
    textState = 2;
  }
  else if (IsKeyPressed(KEY_SPACE) && textState == 2) {
    textState = 3;
  }
  else if (IsKeyPressed(KEY_SPACE) && textState == 3) {
    textState = 0;
  }

 // if (IsKeyPressed(KEY_SPACE)){ textState + 1; }

  switch (textState) {
  default:
    break;
  case 1: DrawText("Line 1", 850,600, 10, WHITE);
    break;
  case 2: DrawText("Line 2", 850,600, 10, WHITE);
    break;
  case 3: DrawText("Line 3", 850,600, 10, WHITE);
    break;
  case 4: text = false;
    break;
  }
}



void Game::Dialog::DialogNext() {}

void Game::Dialog::DialogEnd() {}

Game::Dialog::~Dialog() {}