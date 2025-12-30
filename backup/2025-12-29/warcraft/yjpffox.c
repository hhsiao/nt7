// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m小櫃子[2;37;0m[2;37;0m", ({"guier"}));        
        set("gender", "男性");                
        set("long", "一隻乾癟癟的小烏龜[2;37;0m
它是月兒眉的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "yjpffox");
        set("owner_name", "月兒眉");
        set_temp("owner", "yjpffox");
        set_temp("owner_name", "月兒眉");
        ::setup();
}
