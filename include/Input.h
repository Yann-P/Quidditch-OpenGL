/**
  *  @author Yann Pellegrini
  *
  */


#ifndef __INPUT_H__
#define __INPUT_H__

class Input {
public:

	explicit Input();

	Input(const Input &) = delete;

	/**
	  *  @brief Appel pour vérifier si une touche est appuyée
	  *	 @return le booléen correspondant au fait qu'une touche soit enfoncée ou non
	  */
	bool isDown(int) const;

	/**
	  *  @brief Définir si une touche est appuyée
	  */
	void setKey(int, bool);

private:

	bool _keys[1024];
	
};

#endif