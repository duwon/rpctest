; Listing generated by Microsoft (R) Optimizing Compiler Version 19.22.27905.0 

	TITLE	C:\TouchGFXProjects\RPCTest\TouchGFX\generated\fonts\src\CachedFont.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

msvcjmc	SEGMENT
__E6CB534E_Types@hpp DB 01H
__BA01B0EB_Unicode@hpp DB 01H
__5BB21980_Font@hpp DB 01H
__2A1A961C_ConstFont@hpp DB 01H
__6E911AB4_GeneratedFont@hpp DB 01H
__D7DD0CA1_FontManager@hpp DB 01H
__CFC461D7_vcruntime_new@h DB 01H
__C6D7619D_Texts@hpp DB 01H
__35DAAA0F_TypedText@hpp DB 01H
__BC5ADFCF_FontCache@hpp DB 01H
__D7AF7719_CachedFont@hpp DB 01H
__502ED9E8_CachedFont@cpp DB 01H
msvcjmc	ENDS
PUBLIC	?getPixelData@FontCache@touchgfx@@SAPBEPBUGlyphNode@2@@Z ; touchgfx::FontCache::getPixelData
PUBLIC	?isCached@FontCache@touchgfx@@SA_NPBUGlyphNode@2@@Z ; touchgfx::FontCache::isCached
PUBLIC	?getGlyph@CachedFont@touchgfx@@UBEPBUGlyphNode@2@GAAPBEAAE@Z ; touchgfx::CachedFont::getGlyph
PUBLIC	?getPixelData@CachedFont@touchgfx@@UBEPBEPBUGlyphNode@2@@Z ; touchgfx::CachedFont::getPixelData
PUBLIC	?getKerning@CachedFont@touchgfx@@UBECGPBUGlyphNode@2@@Z ; touchgfx::CachedFont::getKerning
PUBLIC	__JustMyCode_Default
EXTRN	?find@ConstFont@touchgfx@@QBEPBUGlyphNode@2@G@Z:PROC ; touchgfx::ConstFont::find
EXTRN	?getGlyph@FontCache@touchgfx@@QBEPBUGlyphNode@2@GG@Z:PROC ; touchgfx::FontCache::getGlyph
EXTRN	@__CheckForDebuggerJustMyCode@4:PROC
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
; Function compile flags: /Odt
;	COMDAT __JustMyCode_Default
_TEXT	SEGMENT
__JustMyCode_Default PROC				; COMDAT
	push	ebp
	mov	ebp, esp
	pop	ebp
	ret	0
__JustMyCode_Default ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?getKerning@CachedFont@touchgfx@@UBECGPBUGlyphNode@2@@Z
_TEXT	SEGMENT
_this$ = -8						; size = 4
_prevChar$ = 8						; size = 2
_glyph$ = 12						; size = 4
?getKerning@CachedFont@touchgfx@@UBECGPBUGlyphNode@2@@Z PROC ; touchgfx::CachedFont::getKerning, COMDAT
; _this$ = ecx
; File C:\TouchGFXProjects\RPCTest\TouchGFX\generated\fonts\src\CachedFont.cpp
; Line 54
	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi
	push	edi
	push	ecx
	lea	edi, DWORD PTR [ebp-204]
	mov	ecx, 51					; 00000033H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	pop	ecx
	mov	DWORD PTR _this$[ebp], ecx
	mov	ecx, OFFSET __502ED9E8_CachedFont@cpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 56
	xor	al, al
; Line 57
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 204				; 000000ccH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	8
?getKerning@CachedFont@touchgfx@@UBECGPBUGlyphNode@2@@Z ENDP ; touchgfx::CachedFont::getKerning
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?getPixelData@CachedFont@touchgfx@@UBEPBEPBUGlyphNode@2@@Z
_TEXT	SEGMENT
_data$1 = -20						; size = 4
_this$ = -8						; size = 4
_glyph$ = 8						; size = 4
?getPixelData@CachedFont@touchgfx@@UBEPBEPBUGlyphNode@2@@Z PROC ; touchgfx::CachedFont::getPixelData, COMDAT
; _this$ = ecx
; File C:\TouchGFXProjects\RPCTest\TouchGFX\generated\fonts\src\CachedFont.cpp
; Line 9
	push	ebp
	mov	ebp, esp
	sub	esp, 216				; 000000d8H
	push	ebx
	push	esi
	push	edi
	push	ecx
	lea	edi, DWORD PTR [ebp-216]
	mov	ecx, 54					; 00000036H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	pop	ecx
	mov	DWORD PTR _this$[ebp], ecx
	mov	ecx, OFFSET __502ED9E8_CachedFont@cpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 11
	mov	eax, DWORD PTR _glyph$[ebp]
	push	eax
	call	?isCached@FontCache@touchgfx@@SA_NPBUGlyphNode@2@@Z ; touchgfx::FontCache::isCached
	add	esp, 4
	movzx	ecx, al
	test	ecx, ecx
	je	SHORT $LN2@getPixelDa
; Line 13
	mov	eax, DWORD PTR _glyph$[ebp]
	push	eax
	call	?getPixelData@FontCache@touchgfx@@SAPBEPBUGlyphNode@2@@Z ; touchgfx::FontCache::getPixelData
	add	esp, 4
	mov	DWORD PTR _data$1[ebp], eax
; Line 14
	mov	eax, DWORD PTR _data$1[ebp]
	jmp	SHORT $LN1@getPixelDa
; Line 16
	jmp	SHORT $LN1@getPixelDa
$LN2@getPixelDa:
; Line 18
	mov	esi, esp
	mov	eax, DWORD PTR _glyph$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+44]
	mov	eax, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [edx]
	mov	ecx, DWORD PTR [eax+44]
	mov	eax, DWORD PTR [edx+68]
	call	eax
	cmp	esi, esp
	call	__RTC_CheckEsp
$LN1@getPixelDa:
; Line 20
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 216				; 000000d8H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	4
?getPixelData@CachedFont@touchgfx@@UBEPBEPBUGlyphNode@2@@Z ENDP ; touchgfx::CachedFont::getPixelData
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?getGlyph@CachedFont@touchgfx@@UBEPBUGlyphNode@2@GAAPBEAAE@Z
_TEXT	SEGMENT
_fallbackChar$1 = -32					; size = 2
_n$ = -20						; size = 4
_this$ = -8						; size = 4
_unicode$ = 8						; size = 2
_pixelData$ = 12					; size = 4
_bitsPerPixel$ = 16					; size = 4
?getGlyph@CachedFont@touchgfx@@UBEPBUGlyphNode@2@GAAPBEAAE@Z PROC ; touchgfx::CachedFont::getGlyph, COMDAT
; _this$ = ecx
; File C:\TouchGFXProjects\RPCTest\TouchGFX\generated\fonts\src\CachedFont.cpp
; Line 23
	push	ebp
	mov	ebp, esp
	sub	esp, 228				; 000000e4H
	push	ebx
	push	esi
	push	edi
	push	ecx
	lea	edi, DWORD PTR [ebp-228]
	mov	ecx, 57					; 00000039H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	pop	ecx
	mov	DWORD PTR _this$[ebp], ecx
	mov	ecx, OFFSET __502ED9E8_CachedFont@cpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 25
	movzx	eax, WORD PTR _unicode$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+44]
	call	?find@ConstFont@touchgfx@@QBEPBUGlyphNode@2@G@Z ; touchgfx::ConstFont::find
	mov	DWORD PTR _n$[ebp], eax
; Line 27
	cmp	DWORD PTR _n$[ebp], 0
	jne	SHORT $LN2@getGlyph
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+40], 0
	je	SHORT $LN2@getGlyph
; Line 30
	mov	eax, DWORD PTR _this$[ebp]
	movzx	ecx, WORD PTR [eax+36]
	push	ecx
	movzx	edx, WORD PTR _unicode$[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	call	?getGlyph@FontCache@touchgfx@@QBEPBUGlyphNode@2@GG@Z ; touchgfx::FontCache::getGlyph
	mov	DWORD PTR _n$[ebp], eax
$LN2@getGlyph:
; Line 34
	cmp	DWORD PTR _n$[ebp], 0
	jne	SHORT $LN3@getGlyph
	movzx	eax, WORD PTR _unicode$[ebp]
	test	eax, eax
	je	SHORT $LN3@getGlyph
	movzx	eax, WORD PTR _unicode$[ebp]
	cmp	eax, 10					; 0000000aH
	je	SHORT $LN3@getGlyph
; Line 36
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+44]
	mov	edx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [ecx]
	mov	esi, esp
	mov	ecx, DWORD PTR [edx+44]
	mov	edx, DWORD PTR [eax+12]
	call	edx
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	WORD PTR _fallbackChar$1[ebp], ax
; Line 37
	movzx	eax, WORD PTR _fallbackChar$1[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+44]
	call	?find@ConstFont@touchgfx@@QBEPBUGlyphNode@2@G@Z ; touchgfx::ConstFont::find
	mov	DWORD PTR _n$[ebp], eax
; Line 38
	cmp	DWORD PTR _n$[ebp], 0
	jne	SHORT $LN3@getGlyph
; Line 40
	mov	eax, DWORD PTR _this$[ebp]
	movzx	ecx, WORD PTR [eax+36]
	push	ecx
	movzx	edx, WORD PTR _fallbackChar$1[ebp]
	push	edx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	call	?getGlyph@FontCache@touchgfx@@QBEPBUGlyphNode@2@GG@Z ; touchgfx::FontCache::getGlyph
	mov	DWORD PTR _n$[ebp], eax
$LN3@getGlyph:
; Line 44
	cmp	DWORD PTR _n$[ebp], 0
	je	SHORT $LN5@getGlyph
; Line 46
	mov	esi, esp
	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+68]
	call	eax
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	ecx, DWORD PTR _pixelData$[ebp]
	mov	DWORD PTR [ecx], eax
; Line 47
	mov	eax, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [eax]
	mov	esi, esp
	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+48]
	call	eax
	cmp	esi, esp
	call	__RTC_CheckEsp
	mov	ecx, DWORD PTR _bitsPerPixel$[ebp]
	mov	BYTE PTR [ecx], al
; Line 48
	mov	eax, DWORD PTR _n$[ebp]
	jmp	SHORT $LN1@getGlyph
$LN5@getGlyph:
; Line 50
	xor	eax, eax
$LN1@getGlyph:
; Line 51
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 228				; 000000e4H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	12					; 0000000cH
?getGlyph@CachedFont@touchgfx@@UBEPBUGlyphNode@2@GAAPBEAAE@Z ENDP ; touchgfx::CachedFont::getGlyph
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?isCached@FontCache@touchgfx@@SA_NPBUGlyphNode@2@@Z
_TEXT	SEGMENT
tv66 = -196						; size = 4
_g$ = 8							; size = 4
?isCached@FontCache@touchgfx@@SA_NPBUGlyphNode@2@@Z PROC ; touchgfx::FontCache::isCached, COMDAT
; File C:\TouchGFXProjects\RPCTest\TouchGFX\generated\fonts\include\fonts\FontCache.hpp
; Line 50
	push	ebp
	mov	ebp, esp
	sub	esp, 196				; 000000c4H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-196]
	mov	ecx, 49					; 00000031H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	ecx, OFFSET __BC5ADFCF_FontCache@hpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 51
	mov	eax, DWORD PTR _g$[ebp]
	cmp	DWORD PTR [eax], -1
	jne	SHORT $LN3@isCached
	mov	DWORD PTR tv66[ebp], 1
	jmp	SHORT $LN4@isCached
$LN3@isCached:
	mov	DWORD PTR tv66[ebp], 0
$LN4@isCached:
	mov	al, BYTE PTR tv66[ebp]
; Line 52
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 196				; 000000c4H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?isCached@FontCache@touchgfx@@SA_NPBUGlyphNode@2@@Z ENDP ; touchgfx::FontCache::isCached
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?getPixelData@FontCache@touchgfx@@SAPBEPBUGlyphNode@2@@Z
_TEXT	SEGMENT
_glyph$ = 8						; size = 4
?getPixelData@FontCache@touchgfx@@SAPBEPBUGlyphNode@2@@Z PROC ; touchgfx::FontCache::getPixelData, COMDAT
; File C:\TouchGFXProjects\RPCTest\TouchGFX\generated\fonts\include\fonts\FontCache.hpp
; Line 46
	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	ecx, OFFSET __BC5ADFCF_FontCache@hpp
	call	@__CheckForDebuggerJustMyCode@4
; Line 47
	mov	eax, DWORD PTR _glyph$[ebp]
	add	eax, 20					; 00000014H
; Line 48
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?getPixelData@FontCache@touchgfx@@SAPBEPBUGlyphNode@2@@Z ENDP ; touchgfx::FontCache::getPixelData
_TEXT	ENDS
END
