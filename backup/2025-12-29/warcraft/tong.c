// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;33m櫻花[1;35m胭脂駒[2;37;0m[2;37;0m", ({"car"}));        
        set("gender", "男性");                
        set("long", "這匹馬通體紅如胭脂，背部點點白色宛如灑落櫻花，神駿非凡。[2;37;0m
它是佟湘玉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tong");
        set("owner_name", "佟湘玉");
        set_temp("owner", "tong");
        set_temp("owner_name", "佟湘玉");
        ::setup();
}
