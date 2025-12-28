// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m阿萊克斯塔薩[2;37;0m[2;37;0m", ({"wxx"}));        
        set("gender", "女性");                
        set("long", "武小虛座下神獸紅龍女王阿萊克斯塔薩[2;37;0m
它是武小虛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wuxiaoxu");
        set("owner_name", "武小虛");
        set_temp("owner", "wuxiaoxu");
        set_temp("owner_name", "武小虛");
        ::setup();
}
