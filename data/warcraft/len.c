// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m血海汪洋[2;37;0m[2;37;0m[2;37;0m", ({"xuehai"}));        
        set("gender", "女性");                
        set("long", "$RED$血海汪洋$NOR$[2;37;0m
它是向東流的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "len");
        set("owner_name", "向東流");
        set_temp("owner", "len");
        set_temp("owner_name", "向東流");
        ::setup();
}
