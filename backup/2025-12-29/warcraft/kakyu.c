// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m毀容貓[2;37;0m[2;37;0m", ({"huirong"}));        
        set("gender", "男性");                
        set("long", "一隻被母親拋棄不久，寄居在小區草地小木盒子裡的半大貓.[2;37;0m
它是赤色有角的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "kakyu");
        set("owner_name", "赤色有角");
        set_temp("owner", "kakyu");
        set_temp("owner_name", "赤色有角");
        ::setup();
}
