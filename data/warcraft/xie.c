// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m星際戰艦[2;37;0m[2;37;0m", ({"enterprise"}));        
        set("gender", "男性");                
        set("long", "謝曉峰的聯邦星艦進取號[2;37;0m
它是謝曉峰的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xie");
        set("owner_name", "謝曉峰");
        set_temp("owner", "xie");
        set_temp("owner_name", "謝曉峰");
        ::setup();
}
