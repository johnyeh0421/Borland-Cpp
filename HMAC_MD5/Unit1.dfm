object Form1: TForm1
  Left = 192
  Top = 127
  Width = 649
  Height = 215
  Caption = 'HMAC MD5 Tool _JohnYeh v100'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 32
    Width = 63
    Height = 36
    Caption = 'MAC'
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 131
    Width = 57
    Height = 36
    Caption = 'KEY'
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 104
    Top = 24
    Width = 305
    Height = 44
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    Text = '001122334455'
  end
  object Edit2: TEdit
    Left = 104
    Top = 123
    Width = 513
    Height = 36
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object Button1: TButton
    Left = 24
    Top = 75
    Width = 489
    Height = 41
    Caption = 'GEN KEY'
    Font.Charset = JOHAB_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
end
