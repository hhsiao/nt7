#include <ansi.h>
#include <room.h>
inherit ROOM;
string look_left(object me);
string look_right(object me);
void create()
{
         set("short",HIY"中衝"NOR);
         set("long","這個山洞內一塵不染，非常乾淨，光線來自洞頂，似乎有塊非常大的寶石，
   迎面牆壁上掛著兩張圖譜(tupu)，地上放著幾個蒲團，你隨便找了個地方坐了下來。\n"
);

          set("item_desc", ([
             "tupu" : "牆上掛著兩張圖譜(left)(right)，似乎就是六脈神劍的武功要詣。\n",
             "left": (: look_left :),
             "right": (: look_right :),
]));

        
set("exits", ([
               "southwest" : __DIR__"pyd",
        ]));
       
setup();
}
string look_left(object me)
{
       return YEL"\n這張圖譜是一個卷軸舒開，帛面年深日久，已成焦黃之色，圖上開頭寫著： \n"+
       "“六脈神劍”以一陽指指力為根基，將一陽指的指力化作劍氣，有質無形，可稱無形氣劍。所謂六脈，\n"+
       "即手之六脈太陰肺經、厥陰心包經、少陰心經、太陽小腸經、陽明胃經、少陽三焦經,六脈神劍，即\n"+
       "是由六脈勁氣化出的六種無形劍氣。。。緊跟著帛上繪著個裸體男子的圖形，身上註明穴位，以紅線\n"+
       "黑線繪著內力的運走徑道，旁邊注著一行小字“中衝劍運氣法門”。\n" NOR;
}
string look_right(object me)
{
        return YEL"\n這張圖譜是一個卷軸舒開，帛面年深日久，已成焦黃之色，圖上都是縱橫交叉的直線、\n"+
        "圓圈和弧形,但見紅線黑線，縱橫交錯，頭緒紛繁之極，這圖便是中衝劍的劍法，大開大闔，氣勢雄邁，\n"+
        "一招一勢之間凌厲無比。\n" NOR;
}
void init()
{
        add_action("do_study", "yanxi");
        add_action("do_study", "xuexi");
        add_action("do_study", "xiulian");    
}

int do_study(string arg)
{
       object me,weapon;
       string *skill;
       int j,lvl,neili;
       mapping skill_name;
       me=this_player();
       
       neili=me->query("max_neili");
       skill_name=me->query("liumai-shenjian");
       lvl=me->query_skill("liumai-shenjian",1);
       if (skill_name)
       skill=keys(skill_name);
       j=sizeof(skill);
       
       weapon = me->query_temp("weapon");
      
       if(me->is_busy()|| me->is_fighting()) return notify_fail("你正忙著呢！\n");
       if (!arg) return 0;   
     
       if (weapon )
            return notify_fail("你手中拿著東西，怎麼練？\n");   
    
       
       if(arg=="left" ) {
       	
       if (j>2) return notify_fail("你已經竭盡全力去體會圖譜上的精要，可是總感覺體內數道內勁無法運轉自如！\n");	
       if (lvl>30*(j+1)) me->set_skill("liumai-shenjian",30*(j+1));         
      
       if (neili<(j+1)*3000+1500&&!me->query("liumai-shenjian/zhongchong"))
            return notify_fail("你竭盡全力的驅動體內的一陽指真氣，試圖由中衝穴射出無形劍氣，卻無半點勁氣發出。\n");

       
       if (lvl>30*(j+1))
            return notify_fail("你已經竭盡全力去體會圖譜上的精要，可是總感覺內勁無法運氣成束！\n");

       if (me->query("neili",1)<50)
            return notify_fail("你的內力快不夠了！\n");   
       if (me->query("jing",1)<50)
            return notify_fail("你的精神快不夠了！\n");         
       me->receive_damage("jing",40+random(10));
       me->receive_damage("neili",40+random(10));
if (lvl>=30*(j+1)||me->query("liumai-shenjian/zhongchong",1)){
       write("你內力運轉自如，凝聚真氣，中指迎空一劃，嗤嗤聲響，一條無形劍氣自“中衝”穴中激射而出。\n");
       if (!me->query("liumai-shenjian/zhongchong"))
       me->add("liumai-shenjian/zhongchong", 1);
       } else {
       write("你照著圖譜研習中衝劍法的運氣法門，漸漸的悟出其中的精要所在。\n");
       if (!me->query("liumai-shenjian/zhongchong"))
       me->improve_skill("liumai-shenjian", me->query("int"));
       }
       return 1;
  }else if (arg=="right") {
  	
       if (!me->query("liumai-shenjian/zhongchong"))
            return notify_fail("你已經竭盡全力去體會圖譜上的劍法，可惜這一路劍法的劍氣你還沒有練成！\n");
       if (me->query("neili",1)<60)
            return notify_fail("你的內力快不夠了！\n");   
       if (me->query("jing",1)<60)
            return notify_fail("你的精神快不夠了！\n");
       me->receive_damage("jing",50+random(10));
       me->receive_damage("neili",50+random(10));
       write("你照著劍譜研習中衝劍法，漸漸的悟出其中的精要所在。\n");
       me->add_temp("zhongchong", 1);
       if (me->query_temp("zhongchong")>=10) {
       me->add("liumai-shenjian/zhongchong", 1);
       me->set_temp("zhongchong",0);
       write("你凝聚真氣，中指點處，將圖上的中衝劍法演練了一遍。\n");
       }
      return 1;
	}     
 }   
int valid_leave(object me, string dir)
{
       me->set_temp("zhongchong", 0);
       return 1;        
}                    