// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m白虎[2;37;0m[2;37;0m", ({"ashtiger"}));        
        set("gender", "女性");                
        set("long", "這是一隻兇猛的白色老虎,不怒自威[2;37;0m
它是慕容慕的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "ashwing");
        set("owner_name", "慕容慕");
        set_temp("owner", "ashwing");
        set_temp("owner_name", "慕容慕");
        ::setup();
}
