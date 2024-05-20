#include "commons.cpp"
#include "listaDuplamenteEncadeada.cpp"
#include "arvoreBinaria.cpp"

int main() {
  DLinkedList<BinTreeNode>* lista = new DLinkedList<BinTreeNode>;
  BinTree tree;
  string frase = "rato roeu a roupa do rei de roma";

  for (int i = 0; i < frase.length(); i++) { 
    char c = frase[i];
    if(lista->findCharacter(c)){
      lista->updateFreq(c);
    }
    else{
      BinTreeNode* n = new BinTreeNode;
      n->character = c;
      n->freq = 1;
      lista->insert(n);
    }
  } 
  lista->ordenarLista();
  lista->show();

  // o loop não consegue ser feito mais de uma vez. Vou dar uma olhada melhor ainda
  while(lista->length>1){
    BinTreeNode v1, v2, newNode;
    lista->retirar(v1);
    lista->retirar(v2);
    newNode.freq = v1.freq + v2.freq;
    newNode.left = &v1;
    newNode.right = &v2;
    lista->insertInOrder(&newNode);
    lista->show();
  }
  // tree.root = &newNode;

  // tree.inFixedWalk(tree.root);
}
