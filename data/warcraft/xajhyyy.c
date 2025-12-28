// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m小盼盼[2;37;0m[2;37;0m", ({"laohu"}));        
        set("gender", "女性");                
        set("long", "上古神獸[2;37;0m
它是張小璐的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xajhyyy");
        set("owner_name", "張小璐");
        set_temp("owner", "xajhyyy");
        set_temp("owner_name", "張小璐");
        ::setup();
}
