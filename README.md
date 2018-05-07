<div dir="rtl">
<a href="#part1">تنظیمات اولیه پروژه Unreal Engine (اندروید)</a></br>
  <a href="#part2">پیاده‌سازی تبلیغات ویدئویی (Interstitial/Rewarded Video) و بنری تمام صفحه (Interstitial Banner) در پروژه Unreal Engine (اندروید)</a></br>
  <a href="#part3">پیاده سازی تبلیغات بنری استاندارد در پروژه Unreal Engine (اندروید)</a></br>
  <a href="#part4">موارد پیشرفته‌تر در SDK</a></br>
</div>
</br></br>

<div dir="rtl" id="part1">
  <h1>تنظیمات اولیه پروژه Unreal Engine (اندروید)</h>
  <h3>گام ۱: دریافت SDK تپسل</h3>
ابتدا فایل zip مربوط به SDK تپسل را از آدرس زیر دانلود کرده و در پوشه Plugins موجود در روت پروژه خود Extract کنید. اگر این پوشه وجود نداشت آنرا ایجاد کنید.
<p style="text-align: center;"><a href="https://storage.backtory.com/tapsell-server/sdk/tapsell-unrealengine-1.1.0.zip"><button>دریافت فایل</button></a></p>
<p style="text-align: right;">سپس برنامه را یک بار ریستارت کنید.</p>

<h3>گام ۲: دریافت کلید تپسل</h3>
وارد پنل مدیریت تپسل شده و با تعریف یک اپلیکیشن جدید با عنوان پکیج اپلیکیشن اندرویدی خود، یک کلید تپسل دریافت کنید.
<p style="text-align: center;"><a href="https://dashboard.tapsell.ir"><button>ورود به داشبورد تپسل</button></a></p>

<h3>گام ۳:تنظیمات اولیه Sdk</h3>
از منو Edit -&gt; Project Settings -&gt; Platforms -&gt; Android ، دسترسی های زیر را به پروژه اندروید خود اضافه کنید. افزودن مواردی که optional (اختیاری) هستند باعث افزایش کیفیت و بهینه بودن تبلیغات می شود که میتواند بعدا در میزان درآمد شما نیز تاثیر داشته باشند.
<pre direction="ltr"><span style="color: #000080;">android.permission.ACCESS_NETWORK_STATE
android.permission.INTERNET
android.permission.READ_PHONE_STATE   (optional)
android.permission.VIBRATE   (optional)
android.permission.ACCESS_COARSE_LOCATION   (optional)
</span></pre>
&nbsp;
<h3>گام ۴: شروع کار با SDK تپسل</h3>
خطوط زیر را به انتهای فایل DefaultEngine.ini موجود در فولدر Config پروژه خود اضافه کنید:
<pre style="direction: ltr;">[Advertisement]
TapsellAppID=appKey</pre>
ورودی appKey کلید تپسلی است که در گام قبل از پنل تپسل دریافت کردید. حال از منوی

Edit -&gt; Plugins -&gt; Project -&gt; Advertising پلاگین تپسل را Enable کنید و محیط توسعه را ریستارت کنید.

پلاگین تپسل از Blueprint برای اجرا استفاده میکند. برای شروع کار با Sdk تپسل در شروع برنامه کامپوننت آنرا مانند شکل زیر اضافه کنید:
<p style="text-align: center;"><img class="size-full wp-image-2259 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/1.jpg" alt="" width="359" height="168" /></p>


</div>

<div dir="rtl" id="part2">
  <h1>
  پیاده‌سازی تبلیغات ویدئویی (Interstitial/Rewarded Video) و بنری تمام صفحه (Interstitial Banner) در پروژه Unreal Engine (اندروید)
  </h1>
<h3>گام 1: دریافت تبلیغ</h3>
نمایش یک تبلیغ ویدئویی در اپلیکیشن به دو صورت ممکن است صورت پذیرد. یک روش، نمایش تبلیغ بصورت stream می باشد. در این حالت، همزمان که کاربر درحال مشاهده بخشی از تبلیغ است، ادامه آن از اینترنت لود می گردد. ممکن است به دلیل کندی سرعت اینترنت، در این حالت کاربر با مکث های متعددی در هنگام دریافت و مشاهده تبلیغ مواجه شود. برای اینکه کاربر در هنگام نمایش تبلیغ منتظر نماند و تجربه کاربر در استفاده از اپلیکیشن بهبود یابد،روش دیگری نیز در SDK تپسل تعبیه شده است که در آن ابتدا فایل ویدئوی تبلیغاتی بطور کامل بارگذاری شده و سپس تبلیغ نمایش داده می شود.
همچنین در تپسل، تبلیغ می تواند در ناحیه‌های مختلفی از برنامه شما (مانند فروشگاه، انتهای هر مرحله، ابتدای مرحله جهت دریافت امتیاز دوبرابر، دریافت بنزین/لایف و ...) پخش شود. در تپسل به این ناحیه‌ها zone گفته می شود. ناحیه‌های هر اپلیکیشن در پنل تپسل تعریف می شوند.

با فراخوانی تابع زیر، می توانید یک درخواست تبلیغ به تپسل ارسال کرده و یک تبلیغ دریافت نمایید:

<img class="size-full wp-image-2260 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/2.jpg" alt="" width="390" height="212" />

هر درخواست شامل یک ورودی <code>zoneId</code> است که باید آن را از <a href="https://dashboard.tapsell.ir/">داشبورد تپسل</a> در صفحه اپلیکیشن خود دریافت کنید. دقت کنید که این پارامتر نباید خالی باشد. ورودی <code>isCached</code> نشان می دهد که آیا تبلیغ باید ابتدا دانلود شده و سپس به کاربر نشان داده شود یا خیر.

[ht_message mstyle="danger" title="کش کردن ویدئو" " show_icon="" id="" class="" style="" ]تنها در ناحیه‌هایی که کاربر با احتمال زیادی پس از باز کردن اپلیکیشن تبلیغ آن را مشاهده می‌کند، از تبلیغ Cached استفاده کنید. جهت توضیحات بیشتر درباره روش انتخاب متد دریافت مناسب، <a href="https://answers.tapsell.ir/?ht_kb=cached-vs-streamed">اینجا</a> را مطالعه کنید.[/ht_message]

برای دریافت نتیجه درخواست تبلیغ باید Event های مربوط به آنها را در هنگام شروع برنامه Bind کنید. نتیجه درخواست تبلیغ به Event های Bind شده برگردانده می شود. در اکشن onAdAvailable شناسه یک تبلیغ به شما برگردانده می شود که می بایست جهت نمایش تبلیغ از آن استفاده کنید. نمونه پیاده سازی:

<img class="size-full wp-image-2262 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/4.jpg" alt="" width="474" height="333" />

<img class="size-full wp-image-2261 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/3.jpg" alt="" width="817" height="448" />

<img class="size-full wp-image-2263 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/5.jpg" alt="" width="531" height="337" />

<img class="size-full wp-image-2264 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/6.jpg" alt="" width="582" height="338" />

<img class="size-full wp-image-2265 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/7.jpg" alt="" width="402" height="252" />

شمای کلی:

<img class="size-full wp-image-2268 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/Capture.jpg" alt="" width="1579" height="1618" />

توضیحات اکشن های مختلف و شرایط اجرا شدن آن ها در جدول ۱ آمده است.

&nbsp;
<table style="text-align: center; border-collapse: collapse;" width="100%"><caption>جدول ۱ اکشن های دریافت نتیجه درخواست تبلیغ</caption>
<tbody>
<tr style="border-bottom: 1px solid #ddd;">
<th width="40%">تابع</th>
<th width="60%">توضیحات (زمان اجرا)</th>
</tr>
<tr style="background-color: #fefefe;">
<td style="direction: ltr;" width="40%">onErrorAction</td>
<td>هنگامی که هر نوع خطایی در پروسه‌ی دریافت تبلیغ بوجود بیاید</td>
</tr>
<tr style="background-color: #f2f2f2;">
<td style="direction: ltr;" width="40%">onAdAvailableAction</td>
<td width="60%">زمانی که تبلیغ دریافت شده و آماده‌ی نمایش باشد.</td>
</tr>
<tr style="background-color: #fefefe;">
<td style="direction: ltr;" width="40%">onNoAdAvailableAction</td>
<td width="60%">در صورتی که تبلیغی برای نمایش وجود نداشته باشد.</td>
</tr>
<tr style="background-color: #f2f2f2;">
<td style="direction: ltr;" width="40%">onNoNetworkAction</td>
<td width="60%">زمانی که دسترسی به شبکه موجود نباشد.</td>
</tr>
<tr style="background-color: #fefefe;">
<td style="direction: ltr;" width="40%">onExpiring</td>
<td width="60%">زمانی که تبلیغ منقضی شود. هر تبلیغ مدت زمان مشخصی معتبر است و در صورتی که تا قبل از آن نمایش داده نشود منقضی شده و دیگر قابل نمایش نخواهد بود.</td>
</tr>
</tbody>
</table>
&nbsp;
<h3>گام 2: نمایش تبلیغ</h3>
جهت نمایش تبلیغ، می‌توانید از تابع زیر استفاده نمایید (این تابع حداکثر یک بار برای هر تبلیغ قابل اجراست) :

<img class="size-full wp-image-2267 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/9.jpg" alt="" width="320" height="302" />

ورودی <span style="font-family: Consolas, 'Liberation Mono', Courier, monospace;"><span style="font-size: 15.2px; background-color: #f7f7f7;">Ad Id</span></span> شناسه تبلیغی است که در گام قبل و در اکشن <code>onAdAvailable</code> به شما داده شده‌است. ورودی Zone Id نیز مربوط به شناسه zone ای است که برای آن درخواست تبلیغ داده اید. توضیحات سایر ورودی ها در جدول ۲ آورده شده است.

&nbsp;
<table style="text-align: center; border-collapse: collapse;" width="100%" cellpadding="6"><caption>جدول ۲ ورودی های Tapsell Show Ad</caption>
<tbody>
<tr style="border-bottom: 1px solid #ddd;">
<th width="40%">متغیر (نوع)</th>
<th width="60%">توضیحات</th>
</tr>
<tr style="background-color: #fefefe;">
<td style="direction: ltr;" width="40%">Back Disabled</td>
<td width="60%">
<div align="right">در هنگام پخش تبلیغ دکمه‌ی بازگشت گوشی فعال باشد یا خیر</div></td>
</tr>
<tr style="background-color: #f2f2f2;">
<td style="direction: ltr;" width="40%">Immmersive Mode</td>
<td width="60%">
<div align="right">فعال‌سازی حالت Immersive در هنگام پخش تبلیغ (فقط در اندروید)</div></td>
</tr>
<tr style="background-color: #fefefe;">
<td style="direction: ltr;" width="40%">Rotation Mode</td>
<td width="60%">
<div align="right">تعیین وضعیت گوشی در هنگام پخش تبلیغ به یکی از سه حالت:</div>
<div align="left">LOCKED PORTRAIT
LOCKED LANDSCAPE
UNLOCKED
LOCKED REVERSED PORTRAIT
LOCKED REVERSED LANDSCAPE</div></td>
</tr>
<tr style="background-color: #f2f2f2;">
<td style="direction: ltr;" width="40%">Show Dialog</td>
<td width="60%">
<div align="right">نمایش دیالوگ اخطار در هنگام بازگشت از تبلیغات جایزه‌دار</div></td>
</tr>
</tbody>
</table>
&nbsp;
<h3>گام 3: دریافت نتیجه نمایش تبلیغ</h3>
در صورتیکه در اپلیکیشن خود از تبلیغات جایزه‌دار استفاده می‌کنید، جهت دریافت نتیجه نمایش تبلیغ‌ها، باید یک Event مطابق زیر Bind کنید.

<img class="size-full wp-image-2270 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/10-1.jpg" alt="" width="884" height="436" />

پس از نمایش تبلیغ، اکشن onAdShowFinished اجرا می‌شود. درصورتیکه تبلیغ نمایش داده شده جایزه‌دار باشد، متغیر Rewarded دارای مقدار true خواهد بود. همچنین درصورتیکه تبلیغ تا انتها دیده شود، متغیر Completed دارای مقدار true خواهد بود. در صورتی که تبلیغ جایزه‌دار باشد و مشاهده ویدئو تا انتها انجام شده باشد، باید جایزه درون برنامه (سکه، اعتبار، بنزین یا ...) را به کاربر بدهید.
<div id="s3gt_translate_tooltip_mini" class="s3gt_translate_tooltip_mini_box" style="background: initial !important; border: initial !important; border-radius: initial !important; border-spacing: initial !important; border-collapse: initial !important; direction: ltr !important; flex-direction: initial !important; font-weight: initial !important; height: initial !important; letter-spacing: initial !important; min-width: initial !important; max-width: initial !important; min-height: initial !important; max-height: initial !important; margin: auto !important; outline: initial !important; padding: initial !important; position: absolute; table-layout: initial !important; text-align: initial !important; text-shadow: initial !important; width: initial !important; word-break: initial !important; word-spacing: initial !important; overflow-wrap: initial !important; box-sizing: initial !important; display: initial !important; color: inherit !important; font-size: 13px !important; font-family: X-LocaleSpecific,sans-serif,Tahoma,Helvetica !important; line-height: 13px !important; vertical-align: top !important; white-space: inherit !important; left: 733px; top: 1684px;"></div>
<div id="s3gt_translate_tooltip_mini" class="s3gt_translate_tooltip_mini_box" style="background: initial !important; border: initial !important; border-radius: initial !important; border-spacing: initial !important; border-collapse: initial !important; direction: ltr !important; flex-direction: initial !important; font-weight: initial !important; height: initial !important; letter-spacing: initial !important; min-width: initial !important; max-width: initial !important; min-height: initial !important; max-height: initial !important; margin: auto !important; outline: initial !important; padding: initial !important; position: absolute; table-layout: initial !important; text-align: initial !important; text-shadow: initial !important; width: initial !important; word-break: initial !important; word-spacing: initial !important; overflow-wrap: initial !important; box-sizing: initial !important; display: initial !important; color: inherit !important; font-size: 13px !important; font-family: X-LocaleSpecific, sans-serif, Tahoma, Helvetica !important; line-height: 13px !important; vertical-align: top !important; white-space: inherit !important; left: 598px; top: 6047px; opacity: 0.35;"></div></div>
  
  
<div dir="rtl" id="part3">
  <h1>
    پیاده‌سازی تبلیغات بنری استاندارد در پروژه Unreal Engine (اندروید)
    </h1>
    <h3>گام 1: دریافت تبلیغ</h3>
جهت نمایش بنر استاندارد، باید محلی برای نمایش آن در صفحه در نظر بگیرید. بنر استاندارد، دارای سایزهای استانداردی است که در SDK تپسل مشخص شده اند. جهت نمایش بنر، از تابع زیر استفاده کنید:

<img class="size-full wp-image-2289 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/11.jpg" alt="" width="312" height="316" />

مقدار zoneId کلیدی ست که بعد از ساخت اپلیکیشن در پنل و ثبت یک zone از نوع بنری استاندارد دریافت میکنید. ورودی Banner Type اندازه های مختلف را بیان میکند. ورودی Horizontal Gravity نشان میدهد که آیا تبلیغ، بالا یا پایین صفحه باشد، همچنین Vertical Gravity بیان میکند که تبلیغ از جهت عرضی در کجای صفحه باشد.
<div id="s3gt_translate_tooltip_mini" class="s3gt_translate_tooltip_mini_box" style="background: initial !important; border: initial !important; border-radius: initial !important; border-spacing: initial !important; border-collapse: initial !important; direction: ltr !important; flex-direction: initial !important; font-weight: initial !important; height: initial !important; letter-spacing: initial !important; min-width: initial !important; max-width: initial !important; min-height: initial !important; max-height: initial !important; margin: auto !important; outline: initial !important; padding: initial !important; position: absolute; table-layout: initial !important; text-align: initial !important; text-shadow: initial !important; width: initial !important; word-break: initial !important; word-spacing: initial !important; overflow-wrap: initial !important; box-sizing: initial !important; display: initial !important; color: inherit !important; font-size: 13px !important; font-family: X-LocaleSpecific, sans-serif, Tahoma, Helvetica !important; line-height: 13px !important; vertical-align: top !important; white-space: inherit !important; left: 243px; top: 1799px;"></div>
<div id="s3gt_translate_tooltip_mini" class="s3gt_translate_tooltip_mini_box" style="background: initial !important; border: initial !important; border-radius: initial !important; border-spacing: initial !important; border-collapse: initial !important; direction: ltr !important; flex-direction: initial !important; font-weight: initial !important; height: initial !important; letter-spacing: initial !important; min-width: initial !important; max-width: initial !important; min-height: initial !important; max-height: initial !important; margin: auto !important; outline: initial !important; padding: initial !important; position: absolute; table-layout: initial !important; text-align: initial !important; text-shadow: initial !important; width: initial !important; word-break: initial !important; word-spacing: initial !important; overflow-wrap: initial !important; box-sizing: initial !important; display: initial !important; color: inherit !important; font-size: 13px !important; font-family: X-LocaleSpecific, sans-serif, Tahoma, Helvetica !important; line-height: 13px !important; vertical-align: top !important; white-space: inherit !important; left: 836px; top: 338px;"></div>
<div id="s3gt_translate_tooltip_mini" class="s3gt_translate_tooltip_mini_box" style="background: initial !important; border: initial !important; border-radius: initial !important; border-spacing: initial !important; border-collapse: initial !important; direction: ltr !important; flex-direction: initial !important; font-weight: initial !important; height: initial !important; letter-spacing: initial !important; min-width: initial !important; max-width: initial !important; min-height: initial !important; max-height: initial !important; margin: auto !important; outline: initial !important; padding: initial !important; position: absolute; table-layout: initial !important; text-align: initial !important; text-shadow: initial !important; width: initial !important; word-break: initial !important; word-spacing: initial !important; overflow-wrap: initial !important; box-sizing: initial !important; display: initial !important; color: inherit !important; font-size: 13px !important; font-family: X-LocaleSpecific, sans-serif, Tahoma, Helvetica !important; line-height: 13px !important; vertical-align: top !important; white-space: inherit !important; left: 964px; top: 586px; opacity: 0.4;">
<div id="s3gt_translate_tooltip_mini_logo" class="s3gt_translate_tooltip_mini" title="Translate selected text"></div>
<div id="s3gt_translate_tooltip_mini_sound" class="s3gt_translate_tooltip_mini" title="Play"></div>
<div id="s3gt_translate_tooltip_mini_copy" class="s3gt_translate_tooltip_mini" title="Copy text to Clipboard"></div>
</div>
  </div>
  
  
<div dir="rtl" id="part4">
  <h1>
    موارد پیشرفته‌تر در SDK
    </h1>
  <h3>دریافت نسخه SDK تپسل</h3>
درصورتی که نیازمند به دانستن نسخه تپسل پیاده‌سازی شده در اپلیکیشن خود هستید، می‌توانید با فراخوانی تابع زیر عنوان نسخه را دریافت نمایید:

<img class="size-full wp-image-2292 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/12.jpg" alt="" width="253" height="145" />
<h3>تنظیمات کشینگ (اندروید)</h3>
همانطور که گفته شد، از نسخه ۳ به بعد تپسل قابلیت نمایش ویدئو بصورت استریم و همینطور نمایش ویدئو بعد از دانلود فایل (کشینگ) را دارد. با این قابلیت، قبل از نمایش تبلیغ و در هنگامی که کاربر مشغول استفاده از اپلیکیشن است، ویدئو بطور کامل دریافت می‌شود و کاربر بدون هیچگونه مکثی می‌تواند ویدئو را تماشا کند.

از طرف دیگر، در اپلیکیشن‌ها و بازی‌های آنلاین، دریافت ویدئو در پس زمینه ممکن است در روند اصلی برنامه خلل ایجاد کند و آن را کند نماید.

جهت جلوگیری از اشغال پهنای باند زیاد توسط تپسل، شما می‌توانید درصد مشخصی از کل پهنای باند موجود را به دانلود ویدئو اختصاص دهید. جهت انجام این عمل، تابع زیر را در آغاز برنامه (قبل از درخواست تبلیغ) فراخوانی کنید:

<img class="size-full wp-image-2293 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/13.jpg" alt="" width="476" height="190" />

در این تابع، ورودی <code>Max Percentage</code> حداکثر درصدی از پهنای باند در دسترس اپلیکیشن است که SDK تپسل از آن برای دریافت ویدئو استفاده می‌کند.

همچنین درصورتی که از سرعت دانلود واقعی کاربر در اپلیکیشن خود اطلاع دارید می‌توانید به کمک تابع زیر، مقدار حداکثر پهنای باند قابل استفاده برای دانلود ویدئو را به کمک تابع زیر تنظیم کنید.

<img class="size-full wp-image-2294 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/14.jpg" alt="" width="348" height="134" />

ورودی این تابع، میزان حداکثر سرعت دانلود ویدئو است که باید به واحد بایت بر ثانیه داده شود.

در صورتی که در بخشی از اپلیکیشن خود می‌خواهید تنظیمات مربوط به محدودیت سرعت دانلود را غیرفعال نمایید، از تابع زیر استفاده کنید:

<img class="size-full wp-image-2295 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/15.jpg" alt="" width="374" height="122" />

توضیحات بیشتر درباره کشینگ و استریمینگ در SDK تپسل را <a href="https://answers.tapsell.ir/?ht_kb=cached-vs-streamed">اینجا</a> بخوانید.

&nbsp;
<h3>تنظیمات دسترسی‌های زمان اجرا (Run Time Permissions)</h3>
از نسخه اندروید 6 و بالاتر، برخی دسترسی‌ها در اندروید در زمان اجرا باید از کاربر درخواست شوند. یکی از این دسترسی‌ها، دسترسی <code>READ_PHONE_STATE</code> است که توسط تپسل استفاده می‌شود و بدون این دسترسی، SDK تپسل قابل استفاده نیست. برای سهولت در پیاده‌سازی، SDK تپسل دو مود درخواست دسترسی ارائه نموده است. برای تنظیم نحوه درخواست دسترسی، از تابع زیر استفاده کنید.

<img class="size-full wp-image-2296 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/16.jpg" alt="" width="312" height="133" />

در حالت <code>AUTO</code> زمان درخواست تبلیغ درصورت عدم وجود دسترسی مورد نیاز، دیالوگ دریافت دسترسی به کاربر نمایش داده می‌شود. اگر کاربر دسترسی را به اپلیکیشن بدهد تبلیغ دریافت می‌شود و در صورت رد کردن تبلیغ دریافت نمی‌شود. در این حالت اگر کاربر گزینه <code>Don't show again</code> را انتخاب کند دیگر دیالوگ دریافت دسترسی به وی نشان داده نمی‌شود. در حالت <code>AUTO INSIST</code> حتی اگر کاربر گزینه <code>Don't show again</code> را نیز انتخاب کند باز یک دیالوگ به کاربر نمایش داده می‌شود که وی را به صفحه تنظیمات اپ برای تغییر دسترسی مورد نیاز می‌برد.
<h3>حالت دیباگ (Debug Mode)</h3>
در هنگام پیاده‌سازی SDK، ممکن است بدلیل عدم رعایت نکات گفته شده و یا خطاهای دیگر، تبلیغات قابل دریافت و نمایش نباشند. حالت دیباگ جهت تسهیل فرآیند عیب‌یابی در هنگام پیاده‌سازی تعبیه شده است. با فعالسازی این حالت، می‌توانید گزارش‌های لاگ نمایش داده شده توسط SDK را در logcat مشاهده کنید. برای فعالسازی حالت دیباگ کافیست از تابع زیر در آغاز برنامه استفاده کنید:

<img class="size-full wp-image-2297 aligncenter" src="https://answers.tapsell.ir/wp-content/uploads/2017/12/17.jpg" alt="" width="248" height="120" />

سپس با استفاده از نرم‌افزار Android Studio، از بخش Android Monitor، قسمت logcat را باز کرده و لاگ‌های نوشته شده را بررسی کنید. برای مشاهده لاگ‌های برنامه unity، در بخش فیلتر کلمه unity را وارد کنید.
<p style="text-align: center;"><img src="https://answers.tapsell.ir/wp-content/uploads/2017/02/logs-unity.png" /></p>
&nbsp;
<div id="s3gt_translate_tooltip_mini" class="s3gt_translate_tooltip_mini_box" style="background: initial !important; border: initial !important; border-radius: initial !important; border-spacing: initial !important; border-collapse: initial !important; direction: ltr !important; flex-direction: initial !important; font-weight: initial !important; height: initial !important; letter-spacing: initial !important; min-width: initial !important; max-width: initial !important; min-height: initial !important; max-height: initial !important; margin: auto !important; outline: initial !important; padding: initial !important; position: absolute; table-layout: initial !important; text-align: initial !important; text-shadow: initial !important; width: initial !important; word-break: initial !important; word-spacing: initial !important; overflow-wrap: initial !important; box-sizing: initial !important; display: initial !important; color: inherit !important; font-size: 13px !important; font-family: X-LocaleSpecific, sans-serif, Tahoma, Helvetica !important; line-height: 13px !important; vertical-align: top !important; white-space: inherit !important; left: 757px; top: 557px;"></div>
<div id="s3gt_translate_tooltip_mini" class="s3gt_translate_tooltip_mini_box" style="background: initial !important; border: initial !important; border-radius: initial !important; border-spacing: initial !important; border-collapse: initial !important; direction: ltr !important; flex-direction: initial !important; font-weight: initial !important; height: initial !important; letter-spacing: initial !important; min-width: initial !important; max-width: initial !important; min-height: initial !important; max-height: initial !important; margin: auto !important; outline: initial !important; padding: initial !important; position: absolute; table-layout: initial !important; text-align: initial !important; text-shadow: initial !important; width: initial !important; word-break: initial !important; word-spacing: initial !important; overflow-wrap: initial !important; box-sizing: initial !important; display: initial !important; color: inherit !important; font-size: 13px !important; font-family: X-LocaleSpecific, sans-serif, Tahoma, Helvetica !important; line-height: 13px !important; vertical-align: top !important; white-space: inherit !important; left: 968px; top: 1905px;"></div>
<div id="s3gt_translate_tooltip_mini" class="s3gt_translate_tooltip_mini_box" style="background: initial !important; border: initial !important; border-radius: initial !important; border-spacing: initial !important; border-collapse: initial !important; direction: ltr !important; flex-direction: initial !important; font-weight: initial !important; height: initial !important; letter-spacing: initial !important; min-width: initial !important; max-width: initial !important; min-height: initial !important; max-height: initial !important; margin: auto !important; outline: initial !important; padding: initial !important; position: absolute; table-layout: initial !important; text-align: initial !important; text-shadow: initial !important; width: initial !important; word-break: initial !important; word-spacing: initial !important; overflow-wrap: initial !important; box-sizing: initial !important; display: initial !important; color: inherit !important; font-size: 13px !important; font-family: X-LocaleSpecific, sans-serif, Tahoma, Helvetica !important; line-height: 13px !important; vertical-align: top !important; white-space: inherit !important; left: 968px; top: 2597px; opacity: 0.25;"></div>
<div id="s3gt_translate_tooltip_mini" class="s3gt_translate_tooltip_mini_box" style="background: initial !important; border: initial !important; border-radius: initial !important; border-spacing: initial !important; border-collapse: initial !important; direction: ltr !important; flex-direction: initial !important; font-weight: initial !important; height: initial !important; letter-spacing: initial !important; min-width: initial !important; max-width: initial !important; min-height: initial !important; max-height: initial !important; margin: auto !important; outline: initial !important; padding: initial !important; position: absolute; table-layout: initial !important; text-align: initial !important; text-shadow: initial !important; width: initial !important; word-break: initial !important; word-spacing: initial !important; overflow-wrap: initial !important; box-sizing: initial !important; display: initial !important; color: inherit !important; font-size: 13px !important; font-family: X-LocaleSpecific, sans-serif, Tahoma, Helvetica !important; line-height: 13px !important; vertical-align: top !important; white-space: inherit !important; left: 543px; top: 2585px; opacity: 0.65;">
<div id="s3gt_translate_tooltip_mini_logo" class="s3gt_translate_tooltip_mini" title="Translate selected text"></div>
<div id="s3gt_translate_tooltip_mini_sound" class="s3gt_translate_tooltip_mini" title="Play"></div>
<div id="s3gt_translate_tooltip_mini_copy" class="s3gt_translate_tooltip_mini" title="Copy text to Clipboard"></div>
</div>
  </div>

