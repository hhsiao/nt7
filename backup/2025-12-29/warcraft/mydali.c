// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小馬[2;37;0m[2;37;0m", ({"myma"}));        
        set("gender", "男性");                
        set("long", "小馬[2;37;0m
它是妹紙的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "mydali");
        set("owner_name", "妹紙");
        set_temp("owner", "mydali");
        set_temp("owner_name", "妹紙");
        ::setup();
}
