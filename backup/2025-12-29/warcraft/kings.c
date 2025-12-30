// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m獨角獸[1;37m[2;37;0m[2;37;0m", ({"arrow"}));        
        set("gender", "男性");                
        set("long", "你相信嗎，這個一隻烏龜，但是它的名字叫做獨角獸。[2;37;0m
它是威廉的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "kings");
        set("owner_name", "威廉");
        set_temp("owner", "kings");
        set_temp("owner_name", "威廉");
        ::setup();
}
