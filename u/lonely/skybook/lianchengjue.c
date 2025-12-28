#include <ansi.h>

#define DB_D          "/adm/daemons/dbd"
#define DIALOG_D      "/adm/daemons/dialogd"
#define SUICONG_D     "/adm/daemons/suicongd"
#define SKYBOOK_D     "/adm/daemons/skybookd"

inherit ITEM;

連城決
1.找到狄雲，打聽連城劍法
1.找到萬震山 得到連城劍法 得到丁典的消息
2.救出丁典 戰鬥 得到血刀僧的消息
3.打敗落花流水 見到血刀僧
4.救水笙 殺血刀僧 得到財寶消息
5.去破廟開財寶 打敗戚長髮 等人.完成


mapping book_list = ([
        "1"     :    ([ "當前天書" : "連城訣",
                        "當前任務" : "找到狄雲，打聽連城劍法",
                        "npc"      : "wanzhengshan",
                        "下個任務" : "2", ]),
 
        "2"     :    ([ "當前天書" : "連城訣",
                        "當前任務" : "捉拿萬震山，交給狄雲",
                        "條件數值" : 1,
                        "條件描述" : "請您使用指令 register 加上你的完整及真實 email 地址進行註冊\n"
                                  HIR "              提示：電子郵件地址是保障你一切權益的依據，包括你密碼的丟失情況下，我們\n"
                                  HIR "                    通過你註冊的信箱來確認你的身份和歸還你的密碼。" NOR,
                     "獎勵描述" : "jingli:500,neili:1000",
                     HIC "接受到新的任務：輸入 skybook cha 連城訣 查看任務描述！" NOR,
                     "下個獎勵" : "1", ]),
]);

string *sBookMsg1 = ({
        "你翻開《連城訣》，瞬間，一道金光將你籠罩，古舊的書頁上，顯出一行行小字 ……",
        "《連城訣》乃金庸先生創作於1963年，刊載於《東南亞週刊》，書名本做《素心劍》，之後改名為《連城訣》。",
        "此書語言質樸生動，情節緊湊，故事感人，全書充滿了一股悲憤之氣，讀來令人如鯁在喉。",
        "《連城訣》寫世態，寫人心，寫至情至愛，動人心魄，遠遠超出了一般武俠小說的表現範疇，甚至亦非“性情”二字所能概括，可說是金庸作品中的奇特之作。 ",
        "現在，你將扮演書中主角狄雲的身份，進入《連城訣》天書中體驗另外一番奇特的故事，準備好了嗎，正式進入天書世界 ……        ",
        "=---------------------------------  連城訣  ---------------------------------=",
        HIY "《序章》" NOR,
        "你出生在湘南一戶普通農村，自幼父母雙亡，後機緣巧合，被一位武藝高強的老者收養為弟子，這位老者叫戚長髮，你一直叫他師父。",
        "師父從小把你養大成人，教你武藝，待你如親生，你也對師父猶如親生父親一般，感情頗為深厚。",
        "師父有個女兒，叫戚芳，生得清秀可人，比你年紀小兩歲，你叫她師妹，從小你二人青梅竹馬，無話不談，雖未明示，卻早已認定對方為終身伴侶。",
        "你師徒三人，雖生活在農村，可每日務農練劍，與師父海闊天遙，與師妹切磋逗趣，生活得猶如世外桃源一般，好不快活，對江湖上的事情是一無所知。",
        "這一日清早，與往常一樣，師父喚你兄妹二人前去切磋武藝 ……",
});

string *sBookMsg2 = ({
        HIC "你學會了【唐詩劍法】！" NOR,
        "今日，師傅戚長髮繼續讓你和戚芳二人練習唐詩劍法，這劍法自打下就和師妹一起學習，乃師傅的絕學。",
        "戚長髮道：為師傳你這套唐詩劍法，你練得還不夠純熟，一定要多加練習！" ,
        "你應道：是！徒兒一定勤奮練習！",
        "戚長髮點頭道：好！好！那為師過幾日再來考校！ ",
        HIC "將【唐詩】劍法提升到500級後再來(任務完成後輸入skybook start 連城訣)" NOR,
});

string *sBookMsg3 = ({
        HIG "任務達成！" NOR,
        "你恭恭敬敬地向師傅戚長髮磕頭道：師傅，徒兒的唐詩劍法已經練得純熟了，請師傅考校。",
        "戚長髮道：不錯不錯！你且和芳兒切磋一下，為師從旁看看你二人最近的功夫如何。" ,
        "你應道：是！",
        HIC "接受到新的任務：輸入 skybook cha 連城訣 查看任務描述！" NOR,
});

string *sBookMsg4 = ({
        HIG "任務達成！" NOR,
        HIY "《第一章》壽宴" NOR,
        "戚長髮突然跳出，手中竹竿將你震開 ……",        
        "戚長髮道：徒兒武功大有長進，可是還未做到收發自如，以後還得勤加練習，切勿傷人。",
        "你說道：是，師傅！",
        "戚芳：師哥老是欺負我，不練了！",
        "你呵呵笑道：師妹別生氣，以後師哥讓著你就是了。",
        "戚長髮道：天氣逐漸轉涼了，這山野之地寒氣頗重，徒兒有空去打些白狐皮回來，讓芳做幾件皮襖過冬。",
        "你說道：是，徒兒這就去！",
        HIC "接受到新的任務：輸入 skybook cha 連城訣 查看任務描述！" NOR,
});

string *sBookMsg5 = ({
        "戚芳接過你手中的白狐皮大喜：師哥，這白狐皮可是難得，做成皮襖可化雪與三尺之外  ……",
        "戚長髮呵呵笑著讓戚芳快去準備晚飯，明日趕製皮襖，你嚷嚷道去幫師妹洗菜  ……",   
        "師徒三人有說有笑，一騎快馬疾馳而來 ……",
        "馬上那人駛到門前下馬，對戚長髮道：敢問這位老者是否戚長髮戚師叔？",
        "戚長髮道：來者何人？",
        "那人道：原來真是戚師叔，弟子周圻，乃萬震山徒弟。",
        "戚長髮道：我道是誰，原來是大師兄的弟子，說那麼多年不見，找我何事？",
        "周圻道：師傅下月壽辰，在荊州萬府設宴，讓我來請師叔赴宴！",
        "戚長髮道：我和大師兄二十年不見，怎地這次壽宴就來請我了，好好，你回去吧，告訴他我一定來。",
        "周圻應道：“是！” 揚鞭快馬而去！",
        "戚長髮：芳兒，徒兒，好好收拾一下細軟，過幾日咱們要進城了，給你大師伯拜壽！",
        "你和戚芳同時說道：是！",
        HIC "接受到新的任務：輸入 skybook cha 連城訣 查看任務描述！" NOR,
});

string *sBookMsg6 = ({
        "你師徒三人經過半月路程，終於來到了荊州，幾經打聽找到萬府  ……",
        "只見這萬府門庭寬闊，朱牆高瓦，一副大富大貴之氣  ……", 
        "大門前張燈結綵，門庭若市，來往之人穿梭不斷，好不熱鬧。",
        "門前一位約摸五十歲上下年紀的人，身著華服，對來往客人笑臉相迎，相必就是萬震山了。",
        "你和戚芳自小在鄉下長大，未見過這等世面，也不善與人交往，傻傻地站在一旁，師傅戚長髮和萬震山正說著話……",
        "突然間，一人跳出來對萬震山大罵，說辭不堪入耳，話語間知道那人叫呂通，萬震山當年與人結了樑子，今日人家來尋晦氣。",
        "萬震山道：大盜呂通，今日老夫壽辰，你我恩怨改日再論，再不速速離開，休怪我手下不留情。",
        "呂通道：萬震山你個烏龜王八蛋，害我全家，今日必定與你拼個你死我活……",
        
        HIC "接受到新的任務：輸入 skybook cha 連城訣 查看任務描述！" NOR,
});

string *sBookMsg7 = ({
        "見你擊敗大盜呂通後，萬震山拱手道：“小兄弟好身手！”一旁的萬震山弟子們臉露不悅。",
        "萬震山的三徒弟乃他親生兒子，相貌端正，只見他時不時地對著你身旁的戚芳偷看！",
        "萬震山招呼賓朋入座，你和戚芳還有萬震山的八個弟子坐一桌，席間眾人對戚芳美色垂涎三尺，對你譏諷相加……",
        "宴散，人去，夜幕降臨 ……",
        "你在客房中靜坐，突然聽到一聲尖叫，你尋聲飛奔過去，只見一個黑影竄進西面偏房。",
        "你緊跟著分身進入房間，只見房內一片漆黑，哪裡有黑影，正猶豫間，背後猛地一擊。",
        HIR "\n你眼前一黑，接著什麼也不知道了 ……\n" NOR,
        HIC "接受到新的任務：輸入 skybook cha 連城訣 查看任務描述！" NOR,
});

string *sBookMsg8 = ({
        "你悠悠醒轉，只見屋內站滿了人，又萬震山的八個弟子，有家丁，戚芳也在一旁流著眼淚看著你 ……",
        "其中一個弟子道：想不到我家師傅請你們來赴宴，你卻做出這等事情來，連師傅的小妾桃紅你也非禮。",
        "另外一個弟子道：我看他們師徒定是有什麼不可告人的目的，師傅被戚長髮刺傷後重傷在床，戚長髮到是溜得不見人影了。",
        "你正欲起身爭辯，卻發現自己已被五花大綁，渾身無力，你道：究竟怎麼回事？師傅呢，桃紅又是誰，師妹，這，這是怎麼回事？",
        "戚芳道：他們，他們說你非禮桃紅，他們說親眼看到你跟進房來，他們還說師傅刺傷了萬前輩逃跑了。",
        "說完，戚芳唰的流下眼淚 ……",
        "一個弟子道：你別裝蒜了，我們早就看你不對勁，想不到你是這種人，乾脆送官吧！",
        "“對，送官，送官”很多人附和。",
        "你大聲道：師妹，你不相信我麼，我是被冤枉的，你不相信我麼？",
        "戚芳道：“師哥，我相信我信”說完只是低頭流淚，不再做聲！",
        "你心道：師妹定是也相信了這群人所說，自己莫大冤屈不知何處傾述，從小青梅竹馬的師妹，單純不更事，相必也相信了我這個師哥是個淫賊吧！",
        "你心裡想著想著，悲慼萬分！",
        "你正欲開口說話，又是後背猛的一擊，你昏迷了過去！",
        HIR "\n你眼前一黑，接著什麼也不知道了 ……\n" NOR,
        HIC "接受到新的任務：輸入 skybook cha 連城訣 查看任務描述！" NOR,
});


string *sBookMsg9 = ({
        "不知過了多久，你悠悠醒轉，竟然被關進了監獄，四處幽暗無比，蟲鼠穿梭，臭味沖天 ……",
        "你想大聲喊，卻發現無法動彈，或者說一動彈就撕心裂肺地痛 ……",
        "你不斷呻吟，發現自己竟被一跟粗大的鐵鏈穿透了琵琶骨鎖住，一動就痛徹心扉 ……",
        "獄卒過來狠狠地說道：你就在這裡等死吧，不會有人來看你的，你居然得罪了萬家，這輩子就別想出去了。",
        HIY "《第二章》牢獄" NOR,

        HIR "\n你眼前一黑，接著什麼也不知道了 ……\n" NOR,
        HIC "接受到新的任務：輸入 skybook cha 連城訣 查看任務描述！" NOR,
});


void create()
{
        set_name("天書", ({ "skybook lianchengjue" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 0);
                set_weight(0);
        }
        setup();
}

// 移動到劇情副本，根據flag 不同創造不同的劇情副本
// flag代表創建何種房間，比如叫什麼名字的房間，裡面有些什麼NPC
// obx代表返回的創建房間後，同時創建裡面的NPC，最後返回一個NPC的OB編號,若為1則返回ob1
object move_to_room(object me, int flag, int obx)
{
        object obroom;
        object ob1, ob2, ob3, ob4, ob5, ob6, ob7, ob8;
        
        switch(flag)
        {
        case 1: // 出生點，湘南茅屋前
                obroom = new("/clone/skybook14/sky14room");
                obroom->set_name(HIG + "小茅屋" + NOR, ({ "xiaomaowu" }));
              //obroom>set("long", "這裡是北京城的地安門大街。街道是整整齊齊的楊樹林，道上行人絡繹不絕，\n車兩馬匹穿插其中。\n",");  
                obroom->set("long", "這裡是湘南農村的一處農家小院，一個簡陋的茅屋前擺放著一個石桌。\n"); 
                obroom->set("create_time", time());
                ob1 = new("/clone/skybook14/lianchengjue/npc/qichangfa");
                ob2 = new("/clone/skybook14/lianchengjue/npc/qifang");
                ob1->move(obroom);
                ob2->move(obroom);
                me->move(obroom);
        break;
        case 2: // 萬府+呂通
                obroom = new("/clone/skybook14/sky14room");
                obroom->set_name(HIG + "萬府門前" + NOR, ({ "xiaomaowu" }));
              //obroom>set("long", "這裡是北京城的地安門大街。街道是整整齊齊的楊樹林，道上行人絡繹不絕，\n車兩馬匹穿插其中。\n",");  
                obroom->set("long", "這裡是荊州萬府，乃萬震山府邸，四處朱牆高瓦，好不氣派。\n"); 
                obroom->set("create_time", time());
                ob1 = new("/clone/skybook14/lianchengjue/npc/lvtong");
                ob1->move(obroom);
                me->move(obroom);
        break;
        
        case 3: // 萬府 無NPC
                obroom = new("/clone/skybook14/sky14room");
                obroom->set_name(HIG + "萬府門前" + NOR, ({ "xiaomaowu" }));
              //obroom>set("long", "這裡是北京城的地安門大街。街道是整整齊齊的楊樹林，道上行人絡繹不絕，\n車兩馬匹穿插其中。\n",");  
                obroom->set("long", "這裡是荊州萬府，乃萬震山府邸，四處朱牆高瓦，好不氣派。\n"); 
                obroom->set("create_time", time());
                me->move(obroom);
        break;

        case 4: // 萬府廂房 無NPC
                obroom = new("/clone/skybook14/sky14room");
                obroom->set_name(HIG + "廂房" + NOR, ({ "xiaomaowu" }));
              //obroom>set("long", "這裡是北京城的地安門大街。街道是整整齊齊的楊樹林，道上行人絡繹不絕，\n車兩馬匹穿插其中。\n",");  
                obroom->set("long", "這裡是萬府西面的廂房，床上睡著一個女子，周圍站滿了萬府的弟子和家丁。\n"); 
                obroom->set("create_time", time());
                ob1 = new("/clone/skybook14/lianchengjue/npc/qifang");
                ob1->move(obroom);              
                me->move(obroom);
        break;

        case 5: // 牢房 丁典
                obroom = new("/clone/skybook14/sky14room");
                obroom->set_name(HIG + "廂房" + NOR, ({ "xiaomaowu" }));
              //obroom>set("long", "這裡是北京城的地安門大街。街道是整整齊齊的楊樹林，道上行人絡繹不絕，\n車兩馬匹穿插其中。\n",");  
                obroom->set("long", "這裡是荊州大牢，專門關押重犯，四周臭氣熏天，陰暗潮溼。\n"); 
                obroom->set("create_time", time());
                ob1 = new("/clone/skybook14/lianchengjue/npc/dingdian");
                ob1->move(obroom);
                me->move(obroom);
        break;

        default:return;
        }
        
        switch(obx)
        {
        case 1:return ob1;
        case 2:return ob2;
        case 3:return ob3;
        case 4:return ob4;
        case 5:return ob5;
        case 6:return ob6;
        case 7:return ob7;
        case 8:return ob8;                      
        default:return ob1;
        }
}

// 模擬對話完成後調用的入口函數，執行後續操作 me代表玩家，flag 代表編號，用於分辨不同的處理
void dialog_end(object me, int flag)
{
        object ob;
                
        if (! objectp(me))return;
        
        //tell_object(me, "flag = " + sprintf("%d", flag) + "\n");
                        
        switch(flag)
        {
        case 1:
                ob = move_to_room(me, 1, 1);
                DIALOG_D->start_dialog(ob, me, sBookMsg2, 0, 5);
                return;
        break;

        case 5:
                me->set("skybook14/連城訣/任務編號", 5);
                me->set_player_skill("tangshi-jian", 1);
                me->set("skybook14/連城訣/當前任務", "將唐詩劍法提升到500級（任務完成後輸入skybook start 連城訣）");
                
                return;
        break;

        case 10:
                me->set("skybook14/連城訣/任務編號", 10);
                me->set("skybook14/連城訣/當前任務", "與師妹戚芳切磋武藝（fight qi fang）。");

                return;
        break;

        case 15:
                me->set("skybook14/連城訣/任務狀態", 0);
                me->set("skybook14/連城訣/任務編號", 15);
                me->set("skybook14/連城訣/當前任務", "蒐集白狐皮200張。");
                me->set("skybook14/連城訣/當前章節", "第1章");
                return;
        break;

        case 20:
                me->set("skybook14/連城訣/任務狀態", 1);
                me->set("skybook14/連城訣/任務編號", 20);
                me->set("skybook14/連城訣/當前任務", "準備好後就準備前往荊州萬府吧（skybook start 連城訣）");
                me->set("skybook14/連城訣/當前章節", "第1章");
                return;
        break;
        
        case 25:
                me->set("skybook14/連城訣/任務狀態", 0);
                me->set("skybook14/連城訣/任務編號", 25);
                me->set("skybook14/連城訣/當前任務", "擊敗大盜呂通");
                me->set("skybook14/連城訣/當前章節", "第1章");

                ob = environment(me);
                
                return;
        break;  
        
        case 30:
                ob = move_to_room(me, 4, 1);
                me->set("skybook14/連城訣/任務狀態", 0);
                me->set("skybook14/連城訣/任務編號", 30);
                me->set("skybook14/連城訣/當前任務", "輸入start skybook 連城訣 繼續劇情");

                return;
        break;          

        case 35:
                ob = move_to_room(me, 5, 1);
                me->set("skybook14/連城訣/當前章節", "第2章");
                me->set("skybook14/連城訣/任務狀態", 0);
                me->set("skybook14/連城訣/當前任務", "輸入start skybook 連城訣 繼續劇情");
                me->set("skybook14/連城訣/任務編號", 35);

                return;
        break;          
        default:return;
        }
}

// 來自 /cmds/usr/skybook.c調用，開始天書任務
void startbook(object me, string sBook)
{
        int nQuest; // 當前任務編號
        string sZhangjie; // 當前章節
        object ob, ob2;

        sZhangjie = me->query("skybook14/" + sBook + "/當前章節");
        nQuest = me->query("skybook14/" + sBook + "/任務編號");

        switch(nQuest)
        {
        case 1: // 序章
                DIALOG_D->start_dialog4(this_object(), me, sBookMsg1, 0, 1);
                return;
        break;
        
        case 5:// 提升唐詩劍法到500LV
                if (me->query_skill("tangshi-jian", 1) < 500)
                {
                        tell_object(me, me->query("skybook14/連城訣/當前任務") + "\n");
                        return;
                }
                
                ob = move_to_room(me, 1, 1);

                DIALOG_D->start_dialog(ob, me, sBookMsg3, 0, 10);
                
                return;
        break;

        case 10: // 切磋打過戚芳後
                if (me->query("skybook14/連城訣/任務狀態") != 1)
                {       
                        move_to_room(me, 1, 1); // 任務未達成，重新傳送房間

                        tell_object(me, me->query("skybook14/連城訣/當前任務") + "\n");
                        return;
                }

                ob = move_to_room(me, 1, 1);

                DIALOG_D->start_dialog(ob, me, sBookMsg4, 0, 15);

                return;
        break;

        case 15: // 蒐集到200張狐狸皮後
                if (me->query("skybook14/連城訣/任務狀態") != 1)
                {       
                        object ob_hlp;
                        // 檢查是否有200張狐狸皮，如果有則扣除
                        if (! objectp(ob_hlp = present("baihu pi", me)))
                        {
                                tell_object(me, me->query("skybook14/連城訣/當前任務") + "\n");
                                return;
                        }

                        if (base_name(ob_hlp) != "/clone/quarry/item/lipi2")
                                return;
        
                        if (ob_hlp->query_amount() >= 200)
                        {
                                ob_hlp->add_amount(-200);
                                if (ob_hlp->query_amount() < 1)destruct(ob_hlp);
                                tell_object(me, HIG "任務達成！\n" NOR); 
                        }
                        else
                        {
                                tell_object(me, me->query("skybook14/連城訣/當前任務") + "\n");
                                return;
                        }
                        
                        me->set("skybook14/連城訣/任務狀態", 1);
                }

                ob = move_to_room(me, 1, 2);

                DIALOG_D->start_dialog(ob, me, sBookMsg5, 0, 20);

                return;

        break;
        
        case 20: // 前往荊州萬府
                
                ob = move_to_room(me, 2, 1);

                DIALOG_D->start_dialog(ob, me, sBookMsg6, 0, 25);

                return;
        break;  
        
        case 25: // 擊敗大盜呂通
                                        
                if (me->query("skybook14/連城訣/任務狀態") != 1)
                {
                        ob = move_to_room(me, 2, 1); // 任務未達成，重新傳送房間

                        tell_object(me, me->query("skybook14/連城訣/當前任務") + "\n");
                        return;
                }
                
                // 任務達成
                ob = move_to_room(me, 3, 1);

                DIALOG_D->start_dialog4(this_object(), me, sBookMsg7, 0, 30);

                return;

        break;
        
        case 30: // 追黑影入廂房

                // 任務達成
                ob = move_to_room(me, 4, 1);

                DIALOG_D->start_dialog(ob, me, sBookMsg8, 0, 35);

                return;

        break;
                        
        case 35: // 入廂房被打暈

                // 任務達成
                ob = move_to_room(me, 5, 1);

                //DIALOG_D->start_dialog4(ob, me, sBookMsg8, 0, 40);

                return;

        break;

        default:
                tell_object(me, HIY "輸入 skybook cha 連城訣 查看當前任務情況！\n" NOR);
                return;
        }
        
        
        
}
