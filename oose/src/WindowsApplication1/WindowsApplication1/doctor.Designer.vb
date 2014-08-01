<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class doctor
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.Button1 = New System.Windows.Forms.Button
        Me.ListBox1 = New System.Windows.Forms.ListBox
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.Label19 = New System.Windows.Forms.Label
        Me.PrevHistory = New System.Windows.Forms.Button
        Me.NextHistory = New System.Windows.Forms.Button
        Me.Label18 = New System.Windows.Forms.Label
        Me.Label17 = New System.Windows.Forms.Label
        Me.Label16 = New System.Windows.Forms.Label
        Me.Label15 = New System.Windows.Forms.Label
        Me.Label14 = New System.Windows.Forms.Label
        Me.Label13 = New System.Windows.Forms.Label
        Me.Label10 = New System.Windows.Forms.Label
        Me.Label12 = New System.Windows.Forms.Label
        Me.TextBox1 = New System.Windows.Forms.TextBox
        Me.TextBox2 = New System.Windows.Forms.TextBox
        Me.TextBox3 = New System.Windows.Forms.TextBox
        Me.MenuStrip1 = New System.Windows.Forms.MenuStrip
        Me.DatabaseToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.SaveChangesToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.UserToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.LogoutToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.Button2 = New System.Windows.Forms.Button
        Me.TabControl1 = New System.Windows.Forms.TabControl
        Me.TabPage1 = New System.Windows.Forms.TabPage
        Me.TabPage2 = New System.Windows.Forms.TabPage
        Me.TabPage3 = New System.Windows.Forms.TabPage
        Me.Label4 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label11 = New System.Windows.Forms.Label
        Me.Label7 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.Label9 = New System.Windows.Forms.Label
        Me.Label8 = New System.Windows.Forms.Label
        Me.DateTimePicker1 = New System.Windows.Forms.DateTimePicker
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label5 = New System.Windows.Forms.Label
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.MenuStrip1.SuspendLayout()
        Me.TabControl1.SuspendLayout()
        Me.TabPage1.SuspendLayout()
        Me.TabPage2.SuspendLayout()
        Me.TabPage3.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Button1)
        Me.GroupBox1.Controls.Add(Me.ListBox1)
        Me.GroupBox1.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(12, 34)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(248, 171)
        Me.GroupBox1.TabIndex = 1
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Patient Queue"
        '
        'Button1
        '
        Me.Button1.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button1.Location = New System.Drawing.Point(181, 138)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(60, 23)
        Me.Button1.TabIndex = 1
        Me.Button1.Text = "Refresh"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'ListBox1
        '
        Me.ListBox1.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.ListBox1.FormattingEnabled = True
        Me.ListBox1.ItemHeight = 15
        Me.ListBox1.Items.AddRange(New Object() {"<no entries>"})
        Me.ListBox1.Location = New System.Drawing.Point(6, 22)
        Me.ListBox1.Name = "ListBox1"
        Me.ListBox1.Size = New System.Drawing.Size(169, 139)
        Me.ListBox1.TabIndex = 0
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.Label19)
        Me.GroupBox2.Controls.Add(Me.PrevHistory)
        Me.GroupBox2.Controls.Add(Me.NextHistory)
        Me.GroupBox2.Controls.Add(Me.Label18)
        Me.GroupBox2.Controls.Add(Me.Label17)
        Me.GroupBox2.Controls.Add(Me.Label16)
        Me.GroupBox2.Controls.Add(Me.Label15)
        Me.GroupBox2.Controls.Add(Me.Label14)
        Me.GroupBox2.Controls.Add(Me.Label13)
        Me.GroupBox2.Controls.Add(Me.Label10)
        Me.GroupBox2.Controls.Add(Me.Label12)
        Me.GroupBox2.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox2.Location = New System.Drawing.Point(12, 221)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(235, 290)
        Me.GroupBox2.TabIndex = 8
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "History"
        '
        'Label19
        '
        Me.Label19.AutoSize = True
        Me.Label19.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label19.Location = New System.Drawing.Point(100, 264)
        Me.Label19.Name = "Label19"
        Me.Label19.Size = New System.Drawing.Size(55, 15)
        Me.Label19.TabIndex = 62
        Me.Label19.Text = "<index>"
        '
        'PrevHistory
        '
        Me.PrevHistory.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.PrevHistory.Location = New System.Drawing.Point(6, 259)
        Me.PrevHistory.Name = "PrevHistory"
        Me.PrevHistory.Size = New System.Drawing.Size(34, 25)
        Me.PrevHistory.TabIndex = 60
        Me.PrevHistory.Text = "◄"
        Me.PrevHistory.UseVisualStyleBackColor = True
        '
        'NextHistory
        '
        Me.NextHistory.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.NextHistory.Location = New System.Drawing.Point(195, 259)
        Me.NextHistory.Name = "NextHistory"
        Me.NextHistory.Size = New System.Drawing.Size(34, 25)
        Me.NextHistory.TabIndex = 61
        Me.NextHistory.Text = "►"
        Me.NextHistory.UseVisualStyleBackColor = True
        '
        'Label18
        '
        Me.Label18.AutoSize = True
        Me.Label18.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label18.Location = New System.Drawing.Point(15, 61)
        Me.Label18.Name = "Label18"
        Me.Label18.Size = New System.Drawing.Size(85, 15)
        Me.Label18.TabIndex = 9
        Me.Label18.Text = "<complaints>"
        '
        'Label17
        '
        Me.Label17.AutoSize = True
        Me.Label17.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label17.Location = New System.Drawing.Point(15, 128)
        Me.Label17.Name = "Label17"
        Me.Label17.Size = New System.Drawing.Size(77, 15)
        Me.Label17.TabIndex = 8
        Me.Label17.Text = "<diagnosis>"
        '
        'Label16
        '
        Me.Label16.AutoSize = True
        Me.Label16.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label16.Location = New System.Drawing.Point(15, 195)
        Me.Label16.Name = "Label16"
        Me.Label16.Size = New System.Drawing.Size(78, 15)
        Me.Label16.TabIndex = 7
        Me.Label16.Text = "<treatment>"
        '
        'Label15
        '
        Me.Label15.AutoSize = True
        Me.Label15.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label15.Location = New System.Drawing.Point(55, 24)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(109, 15)
        Me.Label15.TabIndex = 6
        Me.Label15.Text = "<date of last visit>"
        '
        'Label14
        '
        Me.Label14.AutoSize = True
        Me.Label14.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label14.Location = New System.Drawing.Point(15, 180)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(72, 15)
        Me.Label14.TabIndex = 5
        Me.Label14.Text = "Treatment"
        '
        'Label13
        '
        Me.Label13.AutoSize = True
        Me.Label13.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label13.Location = New System.Drawing.Point(15, 113)
        Me.Label13.Name = "Label13"
        Me.Label13.Size = New System.Drawing.Size(69, 15)
        Me.Label13.TabIndex = 4
        Me.Label13.Text = "Diagnosis"
        '
        'Label10
        '
        Me.Label10.AutoSize = True
        Me.Label10.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label10.Location = New System.Drawing.Point(15, 46)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(79, 15)
        Me.Label10.TabIndex = 3
        Me.Label10.Text = "Complaints"
        '
        'Label12
        '
        Me.Label12.AutoSize = True
        Me.Label12.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label12.Location = New System.Drawing.Point(15, 24)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(35, 15)
        Me.Label12.TabIndex = 2
        Me.Label12.Text = "Date"
        '
        'TextBox1
        '
        Me.TextBox1.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox1.Location = New System.Drawing.Point(6, 6)
        Me.TextBox1.Multiline = True
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(348, 214)
        Me.TextBox1.TabIndex = 9
        '
        'TextBox2
        '
        Me.TextBox2.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox2.Location = New System.Drawing.Point(6, 6)
        Me.TextBox2.Multiline = True
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.Size = New System.Drawing.Size(348, 214)
        Me.TextBox2.TabIndex = 14
        '
        'TextBox3
        '
        Me.TextBox3.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox3.Location = New System.Drawing.Point(6, 6)
        Me.TextBox3.Multiline = True
        Me.TextBox3.Name = "TextBox3"
        Me.TextBox3.Size = New System.Drawing.Size(348, 214)
        Me.TextBox3.TabIndex = 16
        '
        'MenuStrip1
        '
        Me.MenuStrip1.BackColor = System.Drawing.SystemColors.ControlDark
        Me.MenuStrip1.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.MenuStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.DatabaseToolStripMenuItem, Me.UserToolStripMenuItem})
        Me.MenuStrip1.Location = New System.Drawing.Point(0, 0)
        Me.MenuStrip1.Name = "MenuStrip1"
        Me.MenuStrip1.Size = New System.Drawing.Size(642, 24)
        Me.MenuStrip1.TabIndex = 24
        Me.MenuStrip1.Text = "MenuStrip1"
        '
        'DatabaseToolStripMenuItem
        '
        Me.DatabaseToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.SaveChangesToolStripMenuItem})
        Me.DatabaseToolStripMenuItem.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.DatabaseToolStripMenuItem.Name = "DatabaseToolStripMenuItem"
        Me.DatabaseToolStripMenuItem.Size = New System.Drawing.Size(68, 20)
        Me.DatabaseToolStripMenuItem.Text = "Database"
        '
        'SaveChangesToolStripMenuItem
        '
        Me.SaveChangesToolStripMenuItem.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.SaveChangesToolStripMenuItem.Name = "SaveChangesToolStripMenuItem"
        Me.SaveChangesToolStripMenuItem.Size = New System.Drawing.Size(154, 22)
        Me.SaveChangesToolStripMenuItem.Text = "Save changes"
        '
        'UserToolStripMenuItem
        '
        Me.UserToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.LogoutToolStripMenuItem})
        Me.UserToolStripMenuItem.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.UserToolStripMenuItem.Name = "UserToolStripMenuItem"
        Me.UserToolStripMenuItem.Size = New System.Drawing.Size(44, 20)
        Me.UserToolStripMenuItem.Text = "User"
        '
        'LogoutToolStripMenuItem
        '
        Me.LogoutToolStripMenuItem.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.LogoutToolStripMenuItem.Name = "LogoutToolStripMenuItem"
        Me.LogoutToolStripMenuItem.Size = New System.Drawing.Size(120, 22)
        Me.LogoutToolStripMenuItem.Text = "Logout"
        '
        'Button2
        '
        Me.Button2.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button2.Location = New System.Drawing.Point(530, 488)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(100, 23)
        Me.Button2.TabIndex = 3
        Me.Button2.Text = "Save changes"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'TabControl1
        '
        Me.TabControl1.Controls.Add(Me.TabPage1)
        Me.TabControl1.Controls.Add(Me.TabPage2)
        Me.TabControl1.Controls.Add(Me.TabPage3)
        Me.TabControl1.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TabControl1.Location = New System.Drawing.Point(262, 221)
        Me.TabControl1.Name = "TabControl1"
        Me.TabControl1.SelectedIndex = 0
        Me.TabControl1.Size = New System.Drawing.Size(368, 254)
        Me.TabControl1.TabIndex = 2
        '
        'TabPage1
        '
        Me.TabPage1.Controls.Add(Me.TextBox1)
        Me.TabPage1.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TabPage1.Location = New System.Drawing.Point(4, 24)
        Me.TabPage1.Name = "TabPage1"
        Me.TabPage1.Padding = New System.Windows.Forms.Padding(3)
        Me.TabPage1.Size = New System.Drawing.Size(360, 226)
        Me.TabPage1.TabIndex = 0
        Me.TabPage1.Text = "Complaints"
        Me.TabPage1.UseVisualStyleBackColor = True
        '
        'TabPage2
        '
        Me.TabPage2.Controls.Add(Me.TextBox2)
        Me.TabPage2.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TabPage2.Location = New System.Drawing.Point(4, 24)
        Me.TabPage2.Name = "TabPage2"
        Me.TabPage2.Padding = New System.Windows.Forms.Padding(3)
        Me.TabPage2.Size = New System.Drawing.Size(360, 226)
        Me.TabPage2.TabIndex = 1
        Me.TabPage2.Text = "Diagnosis"
        Me.TabPage2.UseVisualStyleBackColor = True
        '
        'TabPage3
        '
        Me.TabPage3.Controls.Add(Me.TextBox3)
        Me.TabPage3.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TabPage3.Location = New System.Drawing.Point(4, 24)
        Me.TabPage3.Name = "TabPage3"
        Me.TabPage3.Padding = New System.Windows.Forms.Padding(3)
        Me.TabPage3.Size = New System.Drawing.Size(360, 226)
        Me.TabPage3.TabIndex = 2
        Me.TabPage3.Text = "Treatment"
        Me.TabPage3.UseVisualStyleBackColor = True
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.Location = New System.Drawing.Point(290, 100)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(74, 15)
        Me.Label4.TabIndex = 50
        Me.Label4.Text = "Date of birth"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.Location = New System.Drawing.Point(290, 74)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(38, 15)
        Me.Label3.TabIndex = 47
        Me.Label3.Text = "Name"
        '
        'Label11
        '
        Me.Label11.AutoSize = True
        Me.Label11.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label11.Location = New System.Drawing.Point(375, 101)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(145, 15)
        Me.Label11.TabIndex = 49
        Me.Label11.Text = "<day> <month> <year>"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label7.Location = New System.Drawing.Point(336, 75)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(145, 15)
        Me.Label7.TabIndex = 48
        Me.Label7.Text = "<first> <middle> <last>"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(290, 47)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(50, 15)
        Me.Label2.TabIndex = 53
        Me.Label2.Text = "Reg. no."
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label6.Location = New System.Drawing.Point(348, 50)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(66, 15)
        Me.Label6.TabIndex = 54
        Me.Label6.Text = "<reg. no.>"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label9.Location = New System.Drawing.Point(391, 127)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(85, 15)
        Me.Label9.TabIndex = 56
        Me.Label9.Text = "<dept. name>"
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label8.Location = New System.Drawing.Point(290, 126)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(92, 15)
        Me.Label8.TabIndex = 55
        Me.Label8.Text = "Employer/Dept."
        '
        'DateTimePicker1
        '
        Me.DateTimePicker1.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.DateTimePicker1.Location = New System.Drawing.Point(369, 186)
        Me.DateTimePicker1.Name = "DateTimePicker1"
        Me.DateTimePicker1.Size = New System.Drawing.Size(200, 24)
        Me.DateTimePicker1.TabIndex = 57
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(290, 190)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(75, 15)
        Me.Label1.TabIndex = 58
        Me.Label1.Text = "Current date"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Font = New System.Drawing.Font("Lucida Sans Unicode", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label5.Location = New System.Drawing.Point(269, 492)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(0, 15)
        Me.Label5.TabIndex = 59
        '
        'doctor
        '
        Me.AcceptButton = Me.Button1
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 15.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(642, 523)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.DateTimePicker1)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.Label8)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label11)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.TabControl1)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.MenuStrip1)
        Me.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.MainMenuStrip = Me.MenuStrip1
        Me.Margin = New System.Windows.Forms.Padding(4, 3, 4, 3)
        Me.MaximizeBox = False
        Me.Name = "doctor"
        Me.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "doctor"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.MenuStrip1.ResumeLayout(False)
        Me.MenuStrip1.PerformLayout()
        Me.TabControl1.ResumeLayout(False)
        Me.TabPage1.ResumeLayout(False)
        Me.TabPage1.PerformLayout()
        Me.TabPage2.ResumeLayout(False)
        Me.TabPage2.PerformLayout()
        Me.TabPage3.ResumeLayout(False)
        Me.TabPage3.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents ListBox1 As System.Windows.Forms.ListBox
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox3 As System.Windows.Forms.TextBox
    Friend WithEvents MenuStrip1 As System.Windows.Forms.MenuStrip
    Friend WithEvents DatabaseToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents SaveChangesToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents UserToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents LogoutToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents TabControl1 As System.Windows.Forms.TabControl
    Friend WithEvents TabPage1 As System.Windows.Forms.TabPage
    Friend WithEvents TabPage2 As System.Windows.Forms.TabPage
    Friend WithEvents TabPage3 As System.Windows.Forms.TabPage
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents DateTimePicker1 As System.Windows.Forms.DateTimePicker
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label18 As System.Windows.Forms.Label
    Friend WithEvents Label17 As System.Windows.Forms.Label
    Friend WithEvents Label16 As System.Windows.Forms.Label
    Friend WithEvents Label15 As System.Windows.Forms.Label
    Friend WithEvents Label14 As System.Windows.Forms.Label
    Friend WithEvents Label13 As System.Windows.Forms.Label
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents NextHistory As System.Windows.Forms.Button
    Friend WithEvents PrevHistory As System.Windows.Forms.Button
    Friend WithEvents Label19 As System.Windows.Forms.Label
End Class
