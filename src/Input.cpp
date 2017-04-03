#include <Input.h>

Input::Input() {
	for(int i = 0; i < 1024; i++)
		_keys[i] = false;
}



/**
*  @brief Appel pour vérifier si une touche est appuyée
*	 @return le booléen correspondant au fait qu'une touche soit enfoncée ou non
*/
bool Input::isDown(int key) const {
	if(key < 0 || key > 1024)
		return false;
	return _keys[key];
}

/**
*  @brief Définir si une touche est appuyée
*/
void Input::setKey(int key, bool val) {
	_keys[key] = val;
}
