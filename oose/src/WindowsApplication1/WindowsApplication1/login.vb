Public Class login

    Dim dbConn As New ADODB.Connection
    Dim recSet As New ADODB.Recordset

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Try
            Dim sqlStr As String
            Dim passwordStr As String
            Dim userType As Integer
            passwordStr = ""

            If Not TextBox1.Text = "" And Not TextBox2.Text = "" Then
                Label2.Text = ""

                sqlStr = "SELECT * FROM login_list WHERE username='" & Trim(TextBox1.Text) & "'"
                recSet.Open(sqlStr, dbConn)

                If recSet.EOF = False Then
                    passwordStr = Trim(recSet.Fields(1).Value)
                End If

                If passwordStr = TextBox2.Text Then
                    Label2.Text = ""
                    userType = recSet.Fields(2).Value

                    If userType = 1 Then
                        doctor.ShowDialog()
                    ElseIf userType = 2 Then
                        clerk.Show()
                    ElseIf userType = 3 Then
                        pharma.Show()
                    Else
                        Me.Show()
                    End If

                Else
                    Label2.Text = "Incorrect username/password"
                End If

                recSet.Close()

            Else
                Label2.Text = "Empty fields are not allowed"
            End If

            TextBox1.Clear()
            TextBox2.Clear()

        Catch ex As Exception

        End Try

    End Sub

    Private Sub login_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Try
            dbConn.ConnectionString = "Driver={Microsoft ODBC for Oracle};" & "UID=System;PWD=sys"
            dbConn.Open()
        Catch ex As Exception
            MsgBox("Unable to communicate with the database." & vbCrLf & "The program will now terminate.", MsgBoxStyle.Critical, "Error")
            Me.Close()
        End Try
        
        ' ' ' debugging code ' ' ' '
        'doctor.Show()
        ' ' ' to be deleted  ' ' ' '

    End Sub

    Private Sub LinkLabel1_LinkClicked(ByVal sender As System.Object, ByVal e As System.Windows.Forms.LinkLabelLinkClickedEventArgs) Handles LinkLabel1.LinkClicked
        Try
            System.Diagnostics.Process.Start("http://www.esic.nic.in")

        Catch ex As Exception

        End Try

    End Sub

End Class