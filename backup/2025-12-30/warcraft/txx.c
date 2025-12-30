// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "豬[2;37;0m
它是吐息曉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "txx");
        set("owner_name", "吐息曉");
        set_temp("owner", "txx");
        set_temp("owner_name", "吐息曉");
        ::setup();
}
