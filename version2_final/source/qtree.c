#include <stdlib.h>
#include <stdbool.h>

#include "global_var.h"
#include "coords.h"
#include "boat.h"
#include "qtree.h"

#include <stdio.h>

QD_Node* buildNode(QD_TNODE type){
	QD_Node* new = (QD_Node *)malloc(sizeof(QD_Node));
	if(new == NULL) exit(-1);
	new->type = type;
	return new;
}

void destroyNode(QD_Node* node){
	free(node);
}

indexQuad quadrants(Point p,Point corners, int side) {
	int middleX = corners.x + side/2, middleY =  corners.y + side/2;
	if(p.x < middleX){
		if(p.y < middleY){
			return SW;
		}
		return NW;
	}
	else{
		if(p.y < middleY){
			return SE;
		}
		return NE;
	}
}

QD_Node* insertNode(QD_Node* root, QD_Node* node){
	return insertNodeRecursive(root, node, makePoint(0,0), n_matrix);
}

QD_Node* insertNodeRecursive(QD_Node* root, QD_Node* node, Point sw, int side){
	
	if(side == 0){
		printf("ja deu merda\n");
		exit(1);
	} 
	
	if(side == 1){
		printf("tem que ser terminal, side = 1\n");
	}
	
	if(root == NULL){
		printf("inseri num no null, node (%d,%d)\n\n",node -> node.leaf.p.x,node -> node.leaf.p.y);
		root = node;
		return root;
	}

	if(root->type == QDLEAF){
		printf("fiz split para uma nova arvore\n");
		
		QD_Node* aux = buildNode(QDLEAF);
		aux -> node.leaf.p = root -> node.leaf.p;
		aux -> node.leaf.cell = root -> node.leaf.cell;
		
		root -> type = QDNODE;
		for(int i = 0; i < nQuadrants ; i++){
			root -> node.quadrants[i] = NULL;
		}
		
		indexQuad index = quadrants(aux->node.leaf.p,sw,side);
		int middleSide = side/2;
		printf("(%d,%d), side = %d\n",sw.x,sw.y,side);
		switch(index){
			case SW:
				printf("next -- SW\n");
				root->node.quadrants[SW] = insertNodeRecursive(root->node.quadrants[SW],aux,makePoint(sw.x,sw.y), middleSide);
				break;
			case NW:
				printf("next -- NW\n");
				root->node.quadrants[NW] = insertNodeRecursive(root->node.quadrants[NW],aux,makePoint(sw.x,sw.y + middleSide), middleSide);
				break;
			case NE:
				printf("next -- NE\n");
				root->node.quadrants[NE] = insertNodeRecursive(root->node.quadrants[NE],aux,makePoint(sw.x + middleSide, sw.y + middleSide), middleSide);
				break;
			case SE:
				printf("next -- SE\n");
				root->node.quadrants[SE] = insertNodeRecursive(root->node.quadrants[SE],aux,makePoint(sw.x + middleSide, sw.y),middleSide);
				break;
		}
		
	}
	
QD_Node* 

	//Caso recursivo
	indexQuad index = quadrants(node -> node.leaf.p,sw,side);
	int middleSide = side/2;
	printf("(%d,%d), side = %d\n",sw.x,sw.y,side);
	switch(index){
		case SW:
			printf("next -- SW\n");
			root->node.quadrants[SW] = insertNodeRecursive(root->node.quadrants[SW],node,makePoint(sw.x,sw.y), middleSide);
			break;
		case NW:
			printf("next -- NW\n");
			root->node.quadrants[NW] = insertNodeRecursive(root->node.quadrants[NW],node,makePoint(sw.x,sw.y + middleSide), middleSide);
			break;
		case NE:
			printf("next -- NE\n");
			root->node.quadrants[NE] = insertNodeRecursive(root->node.quadrants[NE],node,makePoint(sw.x + middleSide, sw.y + middleSide), middleSide);
			break;
		case SE:
			printf("next -- SE\n");
			root->node.quadrants[SE] = insertNodeRecursive(root->node.quadrants[SE],node,makePoint(sw.x + middleSide, sw.y),middleSide);
			break;
	}
	return root;
}

QD_Node* searchNode(QD_Node* root, Point p){
	return searchNodeRecursive(root,p,makePoint(0,n_matrix),n_matrix);
}

QD_Node* searchNodeRecursive(QD_Node* node, Point p, Point sw, int side){

	if(node == NULL) {
		return NULL;
	}

	if(node->type == QDLEAF){
		if(isEqual(node->node.leaf.p, p)){
			return node;
		}
		else{
			return NULL;
		}
	}

	indexQuad index = quadrants(p,sw,side);
	int middleSide = side/2;
	switch(index){
		case SW:
			return searchNodeRecursive(node->node.quadrants[SW],p,sw, middleSide);
		case NW:
			return searchNodeRecursive(node->node.quadrants[NW],p, makePoint(sw.x,sw.y + middleSide), middleSide);
		case NE:
			return searchNodeRecursive(node->node.quadrants[NE],p, makePoint(sw.x + middleSide, sw.y + middleSide), middleSide);
		case SE:
			return searchNodeRecursive(node->node.quadrants[SE],p, makePoint(sw.x + middleSide, sw.y),middleSide);
		default: exit(1);
	}
}

void removeNode(QD_Node* root, Point destiny){
	if(root == NULL){
		return;
	}

	if(root->type == QDLEAF && isEqual(root->node.leaf.p,destiny)){
		destroyNode(root);
	}

	removeNodeRecursive(root,destiny,makePoint(0,0),n_matrix);
}

void removeNodeRecursive(QD_Node* node, Point destiny, Point sw, int side){
	indexQuad index = quadrants(destiny,sw,side);
	if(node->node.quadrants[index] == NULL){
		return;
	}

	if(isEqual(node->node.quadrants[index]->node.leaf.p, destiny)){
		int sum = 0;
		destroyNode(node->node.quadrants[index]);
		node->node.quadrants[index] = NULL;
		QD_Node* aux = NULL;
		for(int i = 0; i < nQuadrants; i++){
			if(node->node.quadrants[i] != NULL){
				sum++;
				aux = node->node.quadrants[i];
			}
		}
		if(sum == 1){
			destroyNode(node);
			node = aux;
		}
	}

	index = quadrants(destiny,sw,side);
	int middleSide = side/2;
	switch(index){
		case SW:
			removeNodeRecursive(node->node.quadrants[SW],destiny,sw, middleSide);
			return;
		case NW:
			removeNodeRecursive(node->node.quadrants[NW],destiny, makePoint(sw.x,sw.y + middleSide), middleSide);
			return;
		case NE:
			removeNodeRecursive(node->node.quadrants[NE],destiny,makePoint(sw.x + middleSide, sw.y + middleSide), middleSide);
			return;
		case SE:
			removeNodeRecursive(node->node.quadrants[SE],destiny,makePoint(sw.x + middleSide, sw.y),middleSide);
			return;
	}
}
