#include <SFML/Graphics.hpp>   //using namespace sf

#include <time.h>
#include <stdlib.h>
 

float timer = 0.0f, delay = 0.1f;
int num_vertBox = 30, num_horzBox = 20;
int size = 16;

int w = size * num_horzBox;

int h = size * num_vertBox;

int direction;

bool isAlive = true, catchBall = false, win =false;

struct CXK

{
    int xx[7]={0,1,2,3};
    int yy[7]={0,1,2,3,4};
    int d =-1;
    
}s;

static int r;
int getRand(){
    srand((unsigned)time(0));
    int random_integer[20];
    for(int index=0; index<20; index++){
        random_integer[index] = (rand()%20)+1;
    }
    if(r<=20)
    r++;
    return random_integer[r];
}
  
class Ball{
public:
    
    bool isFirst = true;
    // int x, y;    // only need one sprite needed for one food item
 //   srand(time(0));
    bool started = false;
    int x;
    int y;
    int direction2 =-1;
    Ball(){
        x = getRand();
        y = getRand();
    }
    
    void move() {
        started = true;
        if(direction2 ==-1){
        direction2 =rand() % 8 + 1;
              }
        
        if (direction2 == 1){
            
            y -= 1;}
        if (direction2 == 2){
            
            y += 1;}
        if (direction2 ==3){
            
            x -= 1;}
        
        if (direction2 == 4){
            
            x += 1;}
        if (direction2 ==5){
            x -= 1;
            y -= 1;
        }
        if (direction2 ==6){
            x += 1;
            y -= 1;
        }
        if (direction2 ==7){
            x += 1;
            y += 1;
        }
        if (direction2 ==8){
            x -= 1;
            y += 1;
        }
        if (x > num_horzBox){
            x = 0;
        }
        
        if (x < 0){
            x = num_horzBox;
        }
        
        
        if (y > num_vertBox){
            y = 0;
        }
        
        if (y < 0){
            y = num_vertBox;
        }
    }
};

Ball b[6]={{},{},{},{},{},{}};


void move() {
    
    if (direction == 0){
        for(int i=0;i<7;i++){
            s.yy[i]-=1;
        }
        direction =-1;
    }
    
    if (direction == 1){
        for(int i=0;i<7;i++){
            s.yy[i]+=1;
        }
        
         direction =-1;
    }
    
    if (direction == 2){
        for(int i=0;i<7;i++){
            s.xx[i]-=1;
        }
        s.d =1;
         direction =-1;
    }
    if (direction == 3){
        for(int i=0;i<7;i++){
            s.xx[i]+=1;
        }
        s.d =-1;
         direction =-1;
    }
    for(int k=0;k<6;k++){
        if((((s.xx[1] == b[k].x) && (s.yy[1] == b[k].y))||((s.xx[0] == b[k].x) && (s.yy[0] == b[k].y))||((s.xx[1] == b[k].x) && (s.yy[0] == b[k].y))||((s.xx[0] == b[k].x) && (s.yy[1] == b[k].y)))&&b[k].started){
        catchBall = true;
    }else{
    
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
                
        if (((s.xx[i] == b[k].x) && ((s.yy[j] == b[k].y))&&b[k].started))
            
        {
            isAlive = false;
            
            if(delay>0.05f){
                  delay -= 0.01;
            }
            isAlive =false;
            i=7;
        }
        }
        
    }
    }
    }
    if (s.xx[3] > num_horzBox){
        for(int i=3;i>=0;i--){
            s.xx[i] = num_horzBox+(i-3);
        }
    }
    
    if (s.xx[0] < 0){
        for(int i=0;i<7;i++){
            s.xx[i] = i;
        }
    }
    
    if (s.yy[4] > num_vertBox){
        for(int i=4;i>=0;i--){
            s.yy[i] = num_horzBox+(i-4);
        }
       
    }
    
    if (s.yy[0] < 0){
        for(int i=0;i<7;i++){
            s.yy[i] = i;
        }
      
    }
}
int main()

{
    
   // srand(time(0));
    
    int score =0, dance =0;
    sf::RenderWindow window(sf::VideoMode(w, h), "CXK and Ball");
    
    
    sf::Texture t1, t2, t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14;
    
    t1.loadFromFile("pink.png");
    t2.loadFromFile("cai1.png");
    t3.loadFromFile("ball.png");
    t4.loadFromFile("cair.png");
    t5.loadFromFile("caiz.png");
    t6.loadFromFile("baod.png");
    t7.loadFromFile("beiy.png");
    t8.loadFromFile("beiy2.png");
    t9.loadFromFile("beiy1.png");
    t10.loadFromFile("j1.png");
    t11.loadFromFile("j2.png");
    t12.loadFromFile("j3.png");
    t13.loadFromFile("j4.png");
    t14.loadFromFile("green.png");
    sf::Sprite sprite1(t1);
    
    sf::Sprite sprite2(t2);
    
    sf::Sprite sprite3(t3);
    
    sf::Sprite sprite4(t4);
    sf::Sprite sprite5(t5);
    
    sf::Sprite sprite6(t6);
    sf::Sprite sprite7(t7);
    sf::Sprite sprite8(t8);
    
    sf::Sprite sprite9(t9);
    sf::Sprite sprite10(t10);
    
    sf::Sprite sprite11(t11);
    sf::Sprite sprite12(t12);
    sf::Sprite sprite13(t13);
    
    sf::Font font;
    
    sf::Sprite exitButton(t14);
  
    
    font.loadFromFile("sansation.ttf");
    
    sf::Clock clock;
    
    while (window.isOpen())
        
    {
        float time = clock.getElapsedTime().asSeconds();
        
        clock.restart();
        
        timer += time;
        sf::Event e;
        
        while (window.pollEvent(e))
            
        {
            if (e.type == sf::Event::Closed)
                
            {
                window.close();
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction = 0;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction = 1;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction = 2;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction = 3;
        
        
        if (timer > delay && isAlive)
        {
            if(score>=300){
                win =true;
            }
            if(win){
                if(dance >=400){
                    dance =0;
                }
                dance++;
            }
            else if(catchBall){
                if(dance >=600){
                    dance =0;
                }
                dance++;
            }else{
            
            timer = 0;
            score++;
                
            move();
                
            if(score<50){
                b[0].move();
            }else if(score>=50&&score<100){
                b[0].move();
                b[1].move();
            }else if(score>=100&&score<150){
                b[0].move();
                b[1].move();
                b[2].move();
            }else if(score>=150&&score<200){
                b[0].move();
                b[1].move();
                b[2].move();
                b[3].move();
            }else if(score>=200&&score<250){
                b[0].move();
                b[1].move();
                b[2].move();
                b[3].move();
                b[4].move();
            }else if(score>=250){
                b[0].move();
                b[1].move();
                b[2].move();
                b[3].move();
                b[4].move();
                b[5].move();
            }
            }
        }
        
        
        window.clear();
        
        
        for (int i = 0; i < num_horzBox; i++)
            
        {
            for (int j = 0; j < num_vertBox; j++)
                
            {
                
                sprite1.setPosition(i*size, j*size);
                
                window.draw(sprite1);
                
            }
            
        }
        
        if(win){
            if (dance<100){
                 sprite10.setPosition(5*size, 5*size);
                 window.draw(sprite10);
            }else if(dance>=100&&dance<200){
                 sprite11.setPosition(5*size, 5*size);
                 window.draw(sprite11);
            }else if(dance>=200&&dance<300){
                 sprite12.setPosition(5*size, 5*size);
                 window.draw(sprite12);
            }else if(dance>=300&&dance<=400){
                 sprite13.setPosition(5*size, 5*size);
                 window.draw(sprite13);
            }
        }
        else if(catchBall){
            if(dance<100){
                sprite9.setPosition(5*size, 5*size);
                window.draw(sprite9);
            }else if(dance>=100&&dance<200){
                sprite8.setPosition(5*size, 5*size);
                window.draw(sprite8);
            }else if(dance>=200&&dance<300){
                sprite9.setPosition(5*size, 5*size);
                window.draw(sprite9);
            }else if(dance>=300&&dance<400){
                sprite8.setPosition(5*size, 5*size);
                window.draw(sprite8);
            }else if(dance>=400&&dance<500){
                sprite9.setPosition(5*size, 5*size);
                window.draw(sprite9);
            }else if(dance>=500&&dance<=600){
                sprite8.setPosition(5*size, 5*size);
                window.draw(sprite8);
            }
            
        }else{
        if(direction !=-1){
           if(s.d==-1){
            sprite2.setPosition(s.xx[0]*size, s.yy[0]*size);
            window.draw(sprite2);
           }
           else{
           sprite4.setPosition(s.xx[0]*size, s.yy[0]*size);
           window.draw(sprite4);
     //      }
           }
        }else{
            sprite6.setPosition(s.xx[0]*size, s.yy[0]*size);
            window.draw(sprite6);
        }
        }
        if(score<50){
            sprite3.setPosition(b[0].x*size, b[0].y*size);
            window.draw(sprite3);
        }else if(score>=50&&score<100){
            sprite3.setPosition(b[0].x*size, b[0].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[1].x*size, b[1].y*size);
            window.draw(sprite3);
        }else if(score>=100&&score<150){
            sprite3.setPosition(b[0].x*size, b[0].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[1].x*size, b[1].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[2].x*size, b[2].y*size);
            window.draw(sprite3);
        }else if(score>=150&&score<200){
            sprite3.setPosition(b[0].x*size, b[0].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[1].x*size, b[1].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[2].x*size, b[2].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[3].x*size, b[3].y*size);
            window.draw(sprite3);
        }else if(score>=200&&score<250){
            sprite3.setPosition(b[0].x*size, b[0].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[1].x*size, b[1].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[2].x*size, b[2].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[3].x*size, b[3].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[4].x*size, b[4].y*size);
            window.draw(sprite3);
        }else if(score>=250){
            sprite3.setPosition(b[0].x*size, b[0].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[1].x*size, b[1].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[2].x*size, b[2].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[3].x*size, b[3].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[4].x*size, b[4].y*size);
            window.draw(sprite3);
            sprite3.setPosition(b[5].x*size, b[5].y*size);
            window.draw(sprite3);
        }
      
        
        sf::Text atext;
        atext.setFont(font);
        atext.setCharacterSize(20);
        atext.setStyle(sf::Text::Bold);
        atext.setColor(sf::Color::Black);
        atext.setPosition(0,0);
 
        
        std::string text = "Current Score: ";
        if(catchBall ==true){
           // window.draw(startText);
            text = "CXK Catch the BALL!!!!";
        }
        if(!isAlive){
             text = "CXK Lost!!!!!!!";
        }
        if(win ==true){
           // window.draw(startText);
            text = "CXK Win!!!!!!";
        }
        text += std::to_string(score);
        atext.setString(text);
        window.draw(atext);
        window.display();
        
    }
    
    return 0;
    
}
