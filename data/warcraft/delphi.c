// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白貓[2;37;0m[2;37;0m", ({"xiaobai"}));        
        set("gender", "女性");                
        set("long", "上古神獸白虎化成了一隻可愛的小白貓。[2;37;0m
它是降龍的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "delphi");
        set("owner_name", "降龍");
        set_temp("owner", "delphi");
        set_temp("owner_name", "降龍");
        ::setup();
}
