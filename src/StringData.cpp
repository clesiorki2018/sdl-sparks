#include "StringData.hpp"

StringData::StringData(const std::string& type)
{
	setlocale(LC_ALL, "");
	bindtextdomain("StringData", "./po");
	textdomain("StringData");

	if ( type == "GameData" ){
		//0, other
		data.push_back(gettext(" "));
		//1
		data.push_back(gettext(" "));
		//2
		data.push_back(gettext(" "));
		//3
		data.push_back(gettext(" "));
		//4
		data.push_back(gettext(" "));
		//5
		data.push_back(gettext(" "));
		//6
		data.push_back(gettext(" "));
		//7
		data.push_back(gettext(" "));
		//8
		data.push_back(gettext(" "));
		//9, GameData
		data.push_back(gettext("1.  The end of the world is near, and you have the power"));
		//10
		data.push_back(gettext("to save only one kind of animal. What do you save?"));
		//11
		data.push_back(gettext("A.  Sheep"));
		//12
		data.push_back(gettext("B.  Rabbit"));
		//13
		data.push_back(gettext("C.  Deer"));
		//14
		data.push_back(gettext("D.  Horse"));
		//15
		data.push_back(gettext("2.  You travel to Africa and visit a tribe, they insist you"));
		//16
		data.push_back(gettext("take a live animal as a souvenir. Which one will you choose?"));
		//17
		data.push_back(gettext("A.  Lion"));
		//18
		data.push_back(gettext("B.  Monkey"));
		//19
		data.push_back(gettext("C.  Snake"));
		//20
		data.push_back(gettext("D.  Giraffe"));
		//21
		data.push_back(gettext("3.  You did something wrong. God punishes you by turning"));
		//22
		data.push_back(gettext("you into an animal of your choice. You decide to become a:"));
		//23
		data.push_back(gettext("A.  Cat"));
		//24
		data.push_back(gettext("B.  Dog"));
		//25
		data.push_back(gettext("C.  Horse"));
		//26
		data.push_back(gettext("D.  Snake"));
		//27
		data.push_back(gettext("4.  If you have the power to make one species disappear "));
		//28
		data.push_back(gettext("forever, which one will that be?"));
		//29
		data.push_back(gettext("A.  Snake"));
		//30
		data.push_back(gettext("B.  Lion"));
		//31
		data.push_back(gettext("C.  Crocodile"));
		//32
		data.push_back(gettext("D.  Shark"));
		//33
		data.push_back(gettext("5.  If you someday met an animal that could speak in "));
		//34
		data.push_back(gettext("human language, you would want that animal to be a..."));
		//35
		data.push_back(gettext("A.  Horse"));
		//36
		data.push_back(gettext("B.  Sheep"));
		//37
		data.push_back(gettext("C.  Rabbit"));
		//38
		data.push_back(gettext("D.  Bird"));
		//39
		data.push_back(gettext("6.  On an isolated island, you can only have an animal"));
		//40
		data.push_back(gettext("as you companion. You choose:"));
		//41
		data.push_back(gettext("A.  Pig"));
		//42
		data.push_back(gettext("B.  Dog"));
		//43
		data.push_back(gettext("C.  Cow"));
		//44
		data.push_back(gettext("D.  Bird"));
		//45
		data.push_back(gettext("7.  If you had the power to tame all kinds of animals, "));
		//46
		data.push_back(gettext("you'll choose what kind of animal to be your pet?"));
		//47
		data.push_back(gettext("A.  White Tiger"));
		//48
		data.push_back(gettext("B.  Dinosaur"));
		//49
		data.push_back(gettext("C.  Polar Bear"));
		//50
		data.push_back(gettext("D.  Leopard"));
		//51
		data.push_back(gettext("8.  If you could be an animal for 5 minutes, which one "));
		//52
		data.push_back(gettext("you would like to be?"));
		//53
		data.push_back(gettext("A.  Cat"));
		//54
		data.push_back(gettext("B.  Lion"));
		//55
		data.push_back(gettext("C.  Horse"));
		//56
		data.push_back(gettext("D.  Pigeon"));
		//57
		data.push_back(gettext("Loading..."));
	}
	else if ( type == "Common" ){
		//0, other
		data.push_back(gettext("Next pressed."));
		//1
		data.push_back(gettext("Previous pressed."));
		//2
		data.push_back(gettext("Quit Now?"));
		//3
		data.push_back(gettext("Next..."));
		//4
		data.push_back(gettext("Previous..."));
		//5
		data.push_back(gettext("Text Button"));
		//6
		data.push_back(gettext("The Keys To Your Heart"));
		//7
		data.push_back(gettext("Copyright 2008 UVi Soft"));
		//8
		data.push_back(gettext("Begin"));
		//9
		data.push_back(gettext("Hand your choice?"));
		//10
		data.push_back(gettext("Press any key to begin..."));
	}
	else if ( type == "Result" ){
		//0
		data.push_back(gettext("You are attracted to..."));
		//1
		data.push_back(gettext("You are attracted to obedience and warmth."));
		//2
		data.push_back(gettext(" "));
		//3
		data.push_back(gettext("You are attracted to those who have a split personality-"));
		//4
		data.push_back(gettext("cold as ice on the outside but hot as fire in the heart."));
		//5
		data.push_back(gettext("You are attracted to good manners and elegance."));
		//6
		data.push_back(gettext(" "));
		//7
		data.push_back(gettext("You are attracted to those who are unbridled, untrammeled,"));
		//8
		data.push_back(gettext("and free."));
		//9
		data.push_back(gettext("In love, you feel the most alive when..."));
		//10
		data.push_back(gettext("In love, you feel the most alive when things are straight-"));
		//11
		data.push_back(gettext("forward, and you're told that you're loved."));
		//12
		data.push_back(gettext("In love, you feel the most alive when your lover is"));
		//13
		data.push_back(gettext("creative and never lets you feel bored."));
		//14
		data.push_back(gettext("In love, you feel the most alive when everything is"));
		//15
		data.push_back(gettext("uncertain, one moment heaven... the next moment hell."));
		//16
		data.push_back(gettext("In love, you feel the most alive when your partner is"));
		//17
		data.push_back(gettext("patient and never willing to give up on you."));
		//18
		data.push_back(gettext("You'd like to your lover to think you are..."));
		//19
		data.push_back(gettext("You'd like to your lover to think you are stylish"));
		//20
		data.push_back(gettext("and alluring."));
		//21
		data.push_back(gettext("You'd like to your lover to think you are loyal and"));
		//22
		data.push_back(gettext("faithful... that you'll never change."));
		//23
		data.push_back(gettext("You'd like to your lover to think you are optimistic"));
		//24
		data.push_back(gettext("and happy."));
		//25
		data.push_back(gettext("You'd like to your lover to think you are flexible"));
		//26
		data.push_back(gettext("and ready for anything!"));
		//27
		data.push_back(gettext("You would be forced to break up with someone who was..."));
		//28
		data.push_back(gettext("You would be forced to break up with someone who was"));
		//29
		data.push_back(gettext("emotional, moody, and difficult to please."));
		//30
		data.push_back(gettext("You would be forced to break up with someone who was "));
		//31
		data.push_back(gettext("arrogant, acting like the dictator of your life. "));
		//32
		data.push_back(gettext("You would be forced to break up with someone who was  "));
		//33
		data.push_back(gettext("ruthless, cold-blooded, and sarcastic."));
		//34
		data.push_back(gettext("You would be forced to break up with someone who was   "));
		//35
		data.push_back(gettext("insecure and in constant need of reassurance."));
		//36
		data.push_back(gettext("Your ideal relationship is..."));
		//37
		data.push_back(gettext("Your ideal relationship is open. Both of you can talk"));
		//38
		data.push_back(gettext("about everything... no secrets."));
		//39
		data.push_back(gettext("Your ideal relationship is traditional. Without saying"));
		//40
		data.push_back(gettext("anything, both of you communicate with your hearts. "));
		//41
		data.push_back(gettext("Your ideal relationship is comforting. You crave a"));
		//42
		data.push_back(gettext("relationship where you always feel warmth and love."));
		//43
		data.push_back(gettext("Your ideal relationship is lasting. You want a relationship"));
		//44
		data.push_back(gettext("that looks to the future... one you can grow with."));
		//45
		data.push_back(gettext("Your risk of cheating is..."));
		//46
		data.push_back(gettext("Your risk of cheating is high. You can't resist desire"));
		//47
		data.push_back(gettext("and lust."));
		//48
		data.push_back(gettext("Your risk of cheating is zero. You care about society"));
		//49
		data.push_back(gettext("and morality. You would never break a commitment."));
		//50
		data.push_back(gettext("Your risk of cheating is low. Even if you're tempted,"));
		//51
		data.push_back(gettext("you'd try hard not to do it."));
		//52
		data.push_back(gettext("Your risk of cheating is 100%. You are not suited for a"));
		//53
		data.push_back(gettext("monogamous relationship."));
		//54
		data.push_back(gettext("You think of marriage..."));
		//55
		data.push_back(gettext("You think of marriage as something precious. You'll"));
		//56
		data.push_back(gettext("treasure marriage and treat it as sacred."));
		//57
		data.push_back(gettext("You think of marriage pessimistically. You don't think"));
		//58
		data.push_back(gettext("happy marriages exist anymore."));
		//59
		data.push_back(gettext("You think of marriage as something that will confine you."));
		//60
		data.push_back(gettext("You are afraid of marriage."));
		//61
		data.push_back(gettext("You think of marriage something you've always wanted..."));
		//62
		data.push_back(gettext("though you haven't really thought about it."));
		//63
		data.push_back(gettext("In this moment, you think of love as..."));
		//64
		data.push_back(gettext("In this moment, you think of love as something you can"));
		//65
		data.push_back(gettext("get or discard anytime. You're feeling self centered."));
		//66
		data.push_back(gettext("In this moment, you think of love as something you thirst for."));
		//67
		data.push_back(gettext("You'll do anything for love, but you won't fall for it easily."));
		//68
		data.push_back(gettext("In this moment, you think of love as something you don't need."));
		//69
		data.push_back(gettext("You just feel like flirting around and playing right now. "));
		//70
		data.push_back(gettext("In this moment, you think of love as commitment."));
		//71
		data.push_back(gettext("Love only works when both people are totally devoted."));
		//72
		data.push_back(gettext("Restart"));
		//73
		data.push_back(gettext("End"));
	}
	else if ( type == "End" ){
		//0
		data.push_back(gettext("CREDITS"));
		//1
		data.push_back(gettext("Created by"));
		//2
		data.push_back(gettext("Long Fei"));
		//3
		data.push_back(gettext("E-mail: zbln426@163.com"));
		//4
		data.push_back(gettext("Laboratory of ZaiBieLiuNian"));
		//5
		data.push_back(gettext("http://www.cppblog.com/lf426/"));
		//6
		data.push_back(gettext("2008 UVi Soft"));
	}
	else {
		//0
		data.push_back(gettext("NULL"));
	}
}


std::string StringData::operator [](const unsigned int& n) const
{
	if ( n >= data.size() )
		return 0;
	return data[n];
}


